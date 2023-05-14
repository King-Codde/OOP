
#include "alarmclock.h"


void AlarmClock::start() {
    // Создание последовательности событий
    std::vector<Event> eventSequence = generateEventSequence();

    // Вывод событий и их актуальных времен
    for (const auto& event : eventSequence) {
        std::cout << "Событие: " << event.getName() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(event.getDuration()));
    }
}

std::vector<Event> AlarmClock::loadEvents(const std::string& eventFile) {
    std::vector<Event> events;
    std::ifstream inputFile(eventFile);
    std::string eventName;
    int eventDuration;

    while (inputFile >> eventName >> eventDuration) {
        events.emplace_back(eventName, eventDuration);
    }

    return events;
}

std::vector<Event> AlarmClock::generateEventSequence() {
    std::vector<Event> eventSequence;

    for (int i = 0; i < numEvents; ++i) {
        int eventType = rand() % events.size();
        int eventDuration = rand() % 4 + 2;
        eventSequence.push_back(Event(events[eventType].getName(), eventDuration));
    }

    return eventSequence;
}

