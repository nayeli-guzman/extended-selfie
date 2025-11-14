uint64_t *lock;
uint64_t *restock;
uint64_t stock;

uint64_t main () {
	stock = 0;
	lock_init (lock);
	cond_init (restock);

	if (pthread_create () == 0) {
		lock_acquire (lock);
		if (stock == 0) {
			cond_wait (restock, lock);
		}
		stock = stock - 1;
		write (1, "Woke up!", 8);
		lock_release (lock);
	} else {
		lock_acquire (lock);
		stock = stock + 1;
		cond_signal (restock);
		write (1, "Waking..", 8);
		lock_release (lock);
	}
}
