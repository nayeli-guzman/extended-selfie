uint64_t fib(uint64_t n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

void worker(uint64_t* label) {
  uint64_t result;

  while (1) {
    // trabajo pesado para que el scheduler tenga qué repartir
    result = fib(15);

    // imprimimos una letrita identificadora del proceso
    // ignoramos "result" porque no tenemos printf cómodo
    write(1, label, 1);
  }
}

uint64_t main() {
  // Cada proceso tendrá un “nombre” distinto
  uint64_t* A;
  uint64_t* B;
  uint64_t* C;
  uint64_t* D;

  uint64_t pid1;
  uint64_t pid2;
  uint64_t pid3;
  uint64_t pid4;

  scheduler(1); // Modo random

    A = "A";
    B = "B";
    C = "C";
    D = "D";
  
  pid1 = fork();

  // Creamos 3 hijos; el padre será el 4to worker
  if (pid1 == 0) {      // hijo 1
    worker(A);
  }

   pid2 = fork();

   if (pid2 == 0) {      // hijo 2
     worker(B);
   }

//   pid3 = fork();

//   if (pid3 == 0) {      // hijo 3
//     worker(C);
//   }

  // Proceso padre
  worker(D);

  return 0;
}
