[Українська версія](#smart-sun-relay-1)

# Smart Sun Relay Setup Guide

Welcome\! This guide will walk you through setting up your new smart light controller step by step. The process is straightforward and doesn't require special technical skills.

A key feature of this device is its ability to operate **completely autonomously** without an internet connection, provided a real-time clock (RTC) module is installed.

## ⚠️ Important Safety Warning

This device operates on a life-threatening voltage of **230V AC**. All installation and connection work in an electrical cabinet must be performed with adherence to all safety regulations. **Always turn off the corresponding circuit breaker in your electrical panel before beginning any work\!**

-----

## 💡 Step 1: What You'll Need

  * An installed and powered **Smart Sun Relay** device.
  * A **smartphone** or computer with Wi-Fi for setup.
  * The **Name (SSID) and Password** for your home Wi-Fi network (only needed for the initial setup).

-----

## 🔌 Step 2: First Wi-Fi Setup

After mounting and applying power for the first time, the device starts in Access Point (AP) mode, allowing you to connect it to your home network.

1.  **Find the device's Wi-Fi network**. On your smartphone or computer, open the list of available Wi-Fi networks. After a minute, a new network named like **`sun-lights-controller-xxxxxx`** will appear.

2.  **Connect to this network**. When prompted for a password, enter:
    `12345678`

3.  **Open the settings webpage**. After connecting, open a web browser (Chrome, Firefox, Safari) and go to the address:
    `192.168.4.1`

4.  **Configure your home Wi-Fi**. You will see a simple webpage. Find the **"WiFi control"** section.

      * In the **"New Wi-Fi SSID"** field, enter the name of your home Wi-Fi network.
      * In the **"New Wi-Fi Password"** field, enter its password.
      * Click the **"Save and connect to new Wifi"** button.

After saving, the device will reboot and connect to your network, and the temporary access point will disappear.

-----

## ⚙️ Step 3: Basic Device Configuration

Now that the device is on your network, you need to configure it to work correctly.

1.  **Find the device's IP address**. The easiest way is to log into your home router's settings and look at the list of connected devices. Find a client named **`sun-lights-controller-xxxxxx`** and note its IP address (e.g., `192.168.1.15`).

2.  **Open the web interface**. Enter the IP address you found into your browser. You will see the main device control page.

3.  **Configure your geolocation**. This is required for calculating sunrise/sunset.

      * Go to [**Google Maps**](https://www.google.com/maps).
      * Find your home and right-click on it.
      * The first line in the context menu will be your coordinates (e.g., `51.507351, -0.127758`).
      * Copy the first number (`51.507351`) and paste it into the **"Latitude"** field on the device's page.
      * Copy the second number (`-0.127758`) and paste it into the **"Longitude"** field.

4.  **Set your time zone**. In the **"UTC Offset Hours"** field, specify the offset for your region. For Ukraine, this is typically **`2.0`** (or **`3.0`** during daylight saving time). For Spain, it is **`1.0`** (or **`2.0`** in summer).

5.  **Select the operation mode**. In the **"Operation Mode"** dropdown list, choose how the device will function:

      * **`Sun Relay Only`**: Fully automatic mode. The light turns on at night and off during the day.
      * **`Sun Relay with Timer`**: Hybrid mode. At night, the light can be turned on for a set duration with a button.
      * **`Timer only`**: Manual mode. The light can be turned on with a button for a set duration at any time.

6.  **Configure the timer duration**. If you chose a mode with a timer, enter the desired duration in seconds in the **"Light On Duration"** field (e.g., `60`).

All settings are saved automatically.

-----

## 🌐 Step 4: Configuring Autonomous Mode (without Internet)

One of the main advantages of this device is its ability to operate **completely autonomously** without a constant connection to the Internet or Wi-Fi. For this, your device must be equipped with a real-time clock module (**DS1307 RTC**).

1.  **Ensure basic setup is complete.** You must have access to the web interface as described in Step 3.

2.  **Set the time manually.** In the **"Time & Sources"** section, find the **`Set Local Time (YYYY-MM-DD HH:MM)`** field. Enter the current date and time in the specified format (e.g., `2025-08-21 10:30`).

3.  **Apply the time.** Press the **"Apply Time"** button. At this moment, the time will be written directly to the RTC module.

**Done\!** From this point on, the device no longer needs an internet connection for synchronization. It will get the accurate time from the RTC and perform all its functions (calculating sunrise/sunset, operating by mode) completely autonomously, even after a power outage.

-----

## 📖 Detailed Description of Functions and States

### 🌞 What are the offsets for?

Offsets allow you to fine-tune the device's automatic operation.

  * **UTC Offset Hours**: This is the 'correction' for your time zone relative to Coordinated Universal Time (UTC). A correct value is critical for accurate calculations.

  * **Sunrise/Sunset Offset Hours**: These settings let you "nudge" the light's on or off time relative to sunrise/sunset.

      * **Example 1:** If you want the light to turn on 30 minutes **after** sunset, set `Sunset Offset Hours` to `0.5` (half an hour).
      * **Example 2:** If you want the light to turn off 1 hour **before** sunrise, set `Sunrise Offset Hours` to `-1.0`.

### 💡 How to monitor the device status

The main indicator of the device's operation is the **`Control Status`** text sensor on the webpage. It shows what is happening at any given moment.

  * **`☀️ Day: Light is OFF`** or **`🌙 Night: Light is ON`**: Standard statuses for `Sun Relay Only` mode.
  * **`Waiting for Button press`**: The device is in a timer mode and is waiting for a button press.
  * **`☀️ Day: Operation Stop`**: Indicates that the device is in `Sun Relay with Timer` mode during the day, and the timer cannot be activated.
  * **`Countdown: XXs ⏱️`**: Displays the countdown when the timer is active.
  * **`⚠️ ALARM: BUTTON/RELAY STUCK! ⚠️`**: The status for the alarm mode.

### 🚨 Alarm Mode (Stuck Button)

This feature protects your system from hardware malfunctions.

  * **How is it activated?** If the device detects that the physical button has remained pressed after a timer cycle completes, it enters alarm mode.
  * **What happens?** A warning appears in the status, and the device may periodically flash the light to draw attention to the issue.
  * **How to cancel it?** The alarm is **cancelled instantly** as soon as the button returns to its normal state.

-----

## 🏠 Step 5: Home Assistant Integration (Optional)

If you use the Home Assistant smart home system, integration is very simple.

1.  Home Assistant should **automatically discover** the new device on your network. You will receive a notification.
2.  Click "Configure" and confirm the addition.
3.  The device, along with all its sensors and switches, will appear in your Home Assistant.

-----

## ✅ Step 6: Finishing Up

After completing all the settings, your device is ready to work\!

-----

## 🤔 Possible Problems and Solutions

  * **I can't see the `sun-lights-controller-xxxxxx` Wi-Fi network.**
      * Wait 1-2 minutes after powering on the device. Make sure it is receiving power.
  * **The page `192.168.4.1` won't open.**
      * Make sure you are connected to the device's Wi-Fi network, not your home Wi-Fi.
  * **I don't know how to find the device's IP address in my router.**
      * You can use a network scanning mobile app like **Fing** (available for Android and iOS). It will show all devices on your network and their names.

-----

-----

# Посібник з Налаштування Smart Sun Relay

Вітаємо\! Цей посібник допоможе вам крок за кроком налаштувати ваш новий "розумний" контролер освітлення. Процес простий і не вимагає спеціальних технічних знань.

Ключовою особливістю пристрою є можливість **повністю автономної роботи** без підключення до Інтернету, за умови наявності модуля годинника реального часу (RTC).

## ⚠️ Важливе попередження щодо безпеки

Пристрій працює з небезпечною для життя напругою **230В змінного струму**. Всі роботи з монтажу та підключення в електрощиті повинні виконуватися з дотриманням усіх правил безпеки.

-----

## 💡 Крок 1: Що вам знадобиться

  * Встановлений та підключений до живлення **Smart Sun Relay**.
  * **Смартфон** або комп'ютер з Wi-Fi для налаштування.
  * **Ім'я (SSID) та пароль** від вашої домашньої мережі Wi-Fi (потрібні лише для першого налаштування).

-----

## 🔌 Крок 2: Перше налаштування Wi-Fi

Після монтажу та першої подачі живлення пристрій запускається в режимі точки доступу (AP), щоб ви могли підключити його до вашої домашньої мережі.

1.  **Знайдіть Wi-Fi мережу пристрою**. На вашому смартфоні або комп'ютері відкрийте список доступних Wi-Fi мереж. Через хвилину там з'явиться нова мережа з назвою, схожою на **`sun-lights-controller-xxxxxx`**.

2.  **Підключіться до цієї мережі**. Коли система запитає пароль, введіть:
    `12345678`

3.  **Відкрийте веб-сторінку налаштувань**. Після підключення відкрийте веб-браузер (Chrome, Firefox, Safari) і перейдіть за адресою:
    `192.168.4.1`

4.  **Налаштуйте домашній Wi-Fi**. Ви побачите просту веб-сторінку. Знайдіть секцію **"WiFi control"**.

      * У поле **"New Wi-Fi SSID"** введіть назву вашої домашньої Wi-Fi мережі.
      * У поле **"New Wi-Fi Password"** введіть пароль від неї.
      * Натисніть кнопку **"Save and connect to new Wifi"**.

Після збереження пристрій перезавантажиться і підключиться до вашої мережі, а тимчасова точка доступу зникне.

-----

## ⚙️ Крок 3: Базове налаштування пристрою

Тепер, коли пристрій у вашій мережі, потрібно його налаштувати для коректної роботи.

1.  **Знайдіть IP-адресу пристрою**. Найпростіший спосіб — зайти в налаштування вашого домашнього роутера і подивитися список підключених пристроїв. Знайдіть у списку клієнт з назвою **`sun-lights-controller-xxxxxx`** і подивіться його IP-адресу (наприклад, `192.168.1.15`).

2.  **Відкрийте веб-інтерфейс**. Введіть знайдену IP-адресу у вашому браузері. Ви побачите головну сторінку керування пристроєм.

3.  **Налаштуйте геолокацію**. Це потрібно для розрахунку сходу/заходу сонця.

      * Перейдіть на [**Google Карти**](https://www.google.com/maps).
      * Знайдіть свій будинок і натисніть на нього правою кнопкою миші.
      * У меню, що з'явиться, першим рядком будуть ваші координати (наприклад, `40.416775, -3.703790`).
      * Скопіюйте перше число (`40.416775`) і вставте його в поле **"Latitude"** на сторінці пристрою.
      * Скопіюйте друге число (`-3.703790`) і вставте його в поле **"Longitude"**.

4.  **Встановіть часовий пояс**. У полі **"UTC Offset Hours"** вкажіть зміщення для вашого регіону. Для Іспанії це зазвичай **`1.0`** (або **`2.0`** під час дії літнього часу). Для України це **`2.0`** (або **`3.0`** влітку).

5.  **Виберіть режим роботи**. У списку **"Operation Mode"** оберіть, як буде працювати пристрій:

      * **`Sun Relay Only`**: Повністю автоматичний режим. Світло вмикається вночі, вимикається вдень.
      * **`Sun Relay with Timer`**: Гібридний. Вночі світло можна увімкнути на деякий час кнопкою.
      * **`Timer only`**: Ручний. Світло вмикається кнопкою на деякий час в будь-який час доби.

6.  **Налаштуйте тривалість таймера**. Якщо ви обрали режим з таймером, вкажіть у полі **"Light On Duration"** бажаний час роботи світла в секундах (наприклад, `60`).

Всі налаштування зберігаються автоматично.

-----

## 🌐 Крок 4: Налаштування автономної роботи (без Інтернету)

Одна з головних переваг цього пристрою — можливість **повністю автономної роботи** без постійного підключення до Інтернету або Wi-Fi. Для цього ваш пристрій повинен бути оснащений модулем годинника реального часу (**DS1307 RTC**).

1.  **Переконайтесь, що базові налаштування зроблено.** Ви повинні мати доступ до веб-інтерфейсу, як описано в Кроці 3.

2.  **Встановіть час вручну.** У секції **"Time & Sources"** знайдіть поле **`Set Local Time (YYYY-MM-DD HH:MM)`**. Введіть поточну дату та час у вказаному форматі (наприклад, `2025-08-21 10:30`).

3.  **Застосуйте час.** Натисніть кнопку **"Apply Time"**. У цей момент час буде записано безпосередньо в модуль RTC.

**Готово\!** З цієї миті пристрій більше не потребує інтернет-з'єднання для синхронізації. Він буде брати точний час з RTC і виконувати всі свої функції (розрахунок сходу/заходу сонця, робота за режимами) повністю автономно, навіть після зникнення живлення.

-----

## 📖 Детальний опис функцій та станів

### 🌞 Для чого потрібні зміщення (офсети)

Офсети дозволяють тонко налаштувати автоматичну роботу пристрою.

  * **UTC Offset Hours**: Це "поправка" для вашого часового поясу відносно всесвітнього часу (UTC). Правильне значення є критично важливим для точних розрахунків.

  * **Sunrise/Sunset Offset Hours**: Ці налаштування дозволяють "підсунути" час ввімкнення або вимкнення світла відносно сходу/заходу сонця.

      * **Приклад 1:** Якщо ви хочете, щоб світло вмикалося через 30 хвилин **після** заходу сонця, встановіть `Sunset Offset Hours` на `0.5` (пів години).
      * **Приклад 2:** Якщо ви хочете, щоб світло вимикалося за 1 годину **до** сходу сонця, встановіть `Sunrise Offset Hours` на `-1.0`.

### 💡 Як контролювати стан пристрою

Головний індикатор роботи пристрою — це текстовий сенсор **`Control Status`** на веб-сторінці. Він показує, що саме відбувається в даний момент.

  * **`☀️ Day: Light is OFF`** або **`🌙 Night: Light is ON`**: Стандартні статуси для режиму `Sun Relay Only`.
  * **`Waiting for Button press`**: Пристрій знаходиться в одному з режимів таймера і очікує на натискання кнопки.
  * **`☀️ Day: Operation Stop`**: Показує, що пристрій у режимі `Sun Relay with Timer` вдень, і таймер не може бути активований.
  * **`Countdown: XXs ⏱️`**: Відображає зворотний відлік, коли таймер активний.
  * **`⚠️ ALARM: BUTTON/RELAY STUCK! ⚠️`**: Статус режиму тривоги.

### 🚨 Режим тривоги (залипання кнопки)

Ця функція захищає вашу систему від апаратних несправностей.

  * **Як активується?** Якщо після завершення роботи таймера пристрій виявляє, що фізична кнопка залишилася в натиснутому стані, він переходить у режим тривоги.
  * **Що відбувається?** У статусі з'являється попередження, а пристрій може періодично блимати світлом, привертаючи увагу до проблеми.
  * **Як скасувати?** Тривога **скасовується миттєво**, як тільки кнопка повертається у нормальний стан.

-----

## 🏠 Крок 5: Інтеграція з Home Assistant (Опціонально)

Якщо ви користуєтесь системою "розумного будинку" Home Assistant, інтеграція дуже проста.

1.  Home Assistant повинен **автоматично знайти** новий пристрій у вашій мережі. Ви отримаєте сповіщення.
2.  Натисніть "Налаштувати" і підтвердьте додавання.
3.  Пристрій з усіма його сенсорами та перемикачами з'явиться у вашому Home Assistant.

-----

## ✅ Крок 6: Завершення

Після завершення всіх налаштувань ваш пристрій готовий до роботи\!

-----

## 🤔 Можливі проблеми та їх вирішення

  * **Я не бачу Wi-Fi мережу `sun-lights-controller-xxxxxx`.**
      * Зачекайте 1-2 хвилини після ввімкнення живлення. Переконайтеся, що напруга подається на пристрій.
  * **Сторінка `192.168.4.1` не відкривається.**
      * Переконайтеся, що ви точно підключені до Wi-Fi мережі пристрою, а не до вашої домашньої.
  * **Я не знаю, як знайти IP-адресу пристрою в роутері.**
      * Ви можете використати мобільні додатки для сканування мережі, наприклад, **Fing** (доступний для Android та iOS). Він покаже всі пристрої у вашій мережі та їхні імена.
