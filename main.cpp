#include <iostream>
#include <thread>
#include <string>
#include <random>
#include <print>

class Runner {
    int count;
  public:
    int points;
    std::string name;

    Runner(std::string name): count(0), points(0), name(name) {}

    void run() {
      while(count < 100) {
        points += rand() % 1000 + 1; 
        count++;
      }
    }
};

int main() {
  srand(time(0));

  Runner runner1("BMW");
  Runner runner2("Porsche");
  Runner runner3("Ferrari");
  Runner runner4("Aston Martin");
  Runner runner5("Lamborghini");
  Runner runner6("McLaren");
  Runner runner7("Bugatti");
  Runner runner8("Koenigsegg");
  Runner runner9("Pagani");
  Runner runner10("Maserati");

  std::thread thread1([&]() { 
    runner1.run(); 
  });
  std::thread thread2([&]() { 
    runner2.run(); 
  });
  std::thread thread3([&]() { 
    runner3.run(); 
  });
  std::thread thread4([&]() { 
    runner4.run(); 
  });
  std::thread thread5([&]() { 
    runner5.run(); 
  });
  std::thread thread6([&]() { 
    runner6.run(); 
  });
  std::thread thread7([&]() { 
    runner7.run(); 
  });
  std::thread thread8([&]() { 
    runner8.run(); 
  });
  std::thread thread9([&]() { 
    runner9.run(); 
  });
  std::thread thread10([&]() { 
    runner10.run(); 
  });

  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  thread6.join();
  thread7.join();
  thread8.join();
  thread9.join();
  thread10.join();

  // Podium
  std::vector<Runner*> runners = {&runner1, &runner2, &runner3, &runner4, &runner5, &runner6, &runner7, &runner8, &runner9, &runner10};

  std::sort(runners.begin(), runners.end(), [](Runner* a, Runner* b) {
    return a->points > b->points;
  });

  std::println("1st place: {}, with {} points.", runners[0]->name, runners[0]->points);
  std::println("2nd place: {}, with {} points.", runners[1]->name, runners[1]->points);
  std::println("3rd place: {}, with {} points.", runners[2]->name, runners[2]->points);

  return 0;
};