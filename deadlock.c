uint64_t *lock1;
uint64_t *lock2;
uint64_t *lock3;

uint64_t main () {
    uint64_t *foo;
    uint64_t i;
	foo = "Hello World!    ";
    lock1 = malloc (sizeof (uint64_t));
    lock2 = malloc (sizeof (uint64_t));
    lock3 = malloc (sizeof (uint64_t));
    lock_init (lock1);
    lock_init (lock2);
    lock_init (lock3);

    i = fork ();

    if (i == 0) {
        lock_acquire (lock1);
        lock_acquire (lock2);
        lock_acquire (lock3);
    } else {
        lock_acquire (lock3);
        lock_acquire (lock2);
    } 


}
