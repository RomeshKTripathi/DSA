#include <iostream>
#include <chrono>
#include <cstdint>
using namespace std;

uint64_t timeSinceEpochMillisec()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

class Random
{
    int seed;

public:
    Random()
    {
        this->seed = static_cast<long long>(timeSinceEpochMillisec());
        this->seed = this->seed % 1000;
    }

    Random(int seed)
    {
        this->seed = seed % 1000;
    }

    long getRandom()
    {
        long random = this->seed * this->seed;
        long new_seed = random / 10;
        this->seed = new_seed % 1000;
        return random;
    }
};

int main()
{
    int i = 18;
    Random obj = Random(18934);
    while (i--)
    {
        cout << obj.getRandom() % 100 << endl;
    }
}