#include "esphome.h"

optional<bool> is_daytime(time::RealTimeClock *sntp_time,
                          sun::Sun *sun_component,
                          float sunrise_offset_h,
                          float sunset_offset_h) {
  auto current_time_utc = sntp_time->utcnow();
  if (!current_time_utc.is_valid()) return {};

  auto sunrise_utc_opt = sun_component->sunrise(-0.833);
  auto sunset_utc_opt = sun_component->sunset(-0.833);
  if (!sunrise_utc_opt.has_value() || !sunset_utc_opt.has_value()) return {};

  // Допоміжна функція для переведення часу в секунди від початку доби
  auto to_day_seconds = [](const esphome::ESPTime &t) -> long {
    return t.hour * 3600L + t.minute * 60L + t.second;
  };

  long now = to_day_seconds(current_time_utc);
  long sunrise = to_day_seconds(sunrise_utc_opt.value()) + static_cast<long>(sunrise_offset_h * 3600);
  long sunset  = to_day_seconds(sunset_utc_opt.value())  + static_cast<long>(sunset_offset_h * 3600);

  // Нормалізація в межах 0–86399
  sunrise = (sunrise + 86400L) % 86400L;
  sunset  = (sunset  + 86400L) % 86400L;
  now     = now % 86400L;

  if (sunrise <= sunset) {
    // День в межах однієї доби
    return now >= sunrise && now < sunset;
  } else {
    // День перетинає межу доби
    return now >= sunrise || now < sunset;
  }
}