#include "esphome.h"

// Оголошуємо нашу функцію. Вона буде приймати посилання на компоненти
// sntp_time та sun, щоб мати доступ до їхніх даних.
// Вона повертає `optional<bool>`, що дозволяє нам обробити ситуацію,
// коли час або дані про сонце недоступні.
optional<bool> is_daytime(time::RealTimeClock *sntp_time, sun::Sun *sun_component) {
  auto current_time = sntp_time->utcnow();
  if (!current_time.is_valid()) {
    return {}; // Повертаємо пусте значення, якщо час невалідний
  }

  auto sunrise_opt = sun_component->sunrise(-0.833);
  auto sunset_opt = sun_component->sunset(-0.833);
  if (!sunrise_opt.has_value() || !sunset_opt.has_value()) {
    return {}; // Повертаємо пусте значення, якщо дані про сонце недоступні
  }

  int now_seconds = current_time.hour * 3600 + current_time.minute * 60 + current_time.second;
  int sunrise_seconds = sunrise_opt.value().hour * 3600 + sunrise_opt.value().minute * 60 + sunrise_opt.value().second;
  int sunset_seconds = sunset_opt.value().hour * 3600 + sunset_opt.value().minute * 60 + sunset_opt.value().second;

  if (sunrise_seconds < sunset_seconds) {
    return (now_seconds >= sunrise_seconds && now_seconds < sunset_seconds);
  } else {
    return !(now_seconds >= sunset_seconds && now_seconds < sunrise_seconds);
  }
}