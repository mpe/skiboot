#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define __TEST__
#include <timer.h>

#define mftb()	(stamp)
#define sync()

static uint64_t stamp, last;
struct lock;
static inline void lock(struct lock *l) { (void)l; }
static inline void unlock(struct lock *l) { (void)l; }

#include "../timer.c"

#define NUM_TIMERS	100

static struct timer timers[NUM_TIMERS];
static unsigned int rand_shift, count;

static void init_rand(void)
{
	unsigned long max = RAND_MAX;

	/* Get something reasonably small */
	while(max > 0x10000) {
		rand_shift++;
		max >>= 1;
	}
}

static void expiry(struct timer *t, void *data)
{
	(void)data;
	assert(t->target >= last);
	count--;
}

int main(void)
{
	unsigned int i;

	init_rand();
	for (i = 0; i < NUM_TIMERS; i++) {
		init_timer(&timers[i], expiry, NULL);
		schedule_timer(&timers[i], random() >> rand_shift);
	}
	count = NUM_TIMERS;
	while(count) {
		check_timers(false);
		stamp++;
	}
	return 0;
}
