#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>
#include <cmath>
using namespace std;

const int kCount = 1000;
const double kPI = 3.1415926;
const int kInterval = 600;
const double kSplit = 0.01;

uint64_t GetTicks() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(int argc, char *argv[]) {
  uint64_t busy_span[kCount];
  uint64_t idle_span[kCount];
  double radian = 0.0;
  int half = kInterval / 2;
  for (int i = 0; i < kCount; i++) {
    busy_span[i] = kInterval / 2 * (1 + sin(kPI * radian));
    idle_span[i] = kInterval - busy_span[i];
    radian += kSplit;
  }

  int j = 0;
  while (true) {
    j = j % kCount;
    uint64_t start_time = GetTicks();
    while (GetTicks() - start_time <= busy_span[j])
    {}
    usleep(idle_span[j]);
    j++;
  }
  
  return 0;
}
