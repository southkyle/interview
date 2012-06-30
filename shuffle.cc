// Problem 1
// 有一个文件，一行行的读，如何随机挑选一行，最多只能保留一行？
// 解答：读到第一行时保留，读到第二行时，以1/2的概率取第二行，如果取到则舍弃只前
// 保留的那一行。

// 读到第n行时，以1/n的概率取该行，如果取到则保留该行，去掉之前保留的那一行。

// 证明：
// n = 1 : 1/1的概率取ok
//   假设 n时，取到的概率为1/n，
//   第n+1行被取到的概率是1/(n+1), 被舍弃的概率是n/(n+1)
//   之前那一行保留的概率时 1/n * n/(n+1) == 1/(n+1)
//   证毕， ok
  
// 如何随机挑选m行？
//   前m行都保留，第n行时，以m/n的概率取这一行，如果没取到，不做处理
//   如果取到，则以1/m的概率从已有的m行中，随机挑一个去掉

// 证明：
//   n=m ok
//   假设 n时，被取到的概率均为m/n
//   n+1行被取到的概率时m/n+1

//   前面m个小球保留的概率是
//   n+1行没有被取到 (n+1-m) / (n+1)
//   n+1行被取到     m/(n+1) * (m-1) / m (未被挑中的概率)
//   m/n * ( (n+1-m)/(n+1) + m/(n+1) * (m-1)/m ) = m / (n+1)

// Problem2
// 如何将数组打乱？

int Rand(int first, int last) {
  // 等概率的产生first，last之间的一个整数
  return bigrand() % (last - first + 1) + first;
}

void Shuffle(int array[], size_t n) {
  for (int i = 0; i < n; i++) {
    j = Rand(i, n-1);
    Swap(&array[i], &array[j]);
  }
}

// 如何从1-n中随机挑选m个数？

void RandomSelect(int n, int m) {
  // m/n 的概率挑选第一个，选中则以m-1 / n-1的概率挑选第二个
  // 否则以 m / n - 1 的概率挑选第二个
  for (int i = 1; i <= n; i++) {
    if (Rand(1, n - i + 1) <= m) {
      cout << i <<  endl;
      m--;
    }
  }
  
}


void RandSelect2(int n, int m) {
  for (int i = 0; i < n; i++) {
    if  (bigrand() % (n-i) < m ) {
      cout << i << endl;
      m--;
    }
  }
}
