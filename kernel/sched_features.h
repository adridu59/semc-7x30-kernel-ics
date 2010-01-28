/*
 * Disregards a certain amount of sleep time (sched_latency_ns) and
 * considers the task to be running during that period. This gives it
 * a service deficit on wakeup, allowing it to run sooner.
 */
SCHED_FEAT(FAIR_SLEEPERS, 1)

/*
 * Only give sleepers 50% of their service deficit. This allows
 * them to run sooner, but does not allow tons of sleepers to
 * rip the spread apart.
 */
SCHED_FEAT(GENTLE_FAIR_SLEEPERS, 1)

/*
 * By not normalizing the sleep time, heavy tasks get an effective
 * longer period, and lighter task an effective shorter period they
 * are considered running.
 */
SCHED_FEAT(NORMALIZED_SLEEPER, 0)

/*
 * Place new tasks ahead so that they do not starve already running
 * tasks
 */
SCHED_FEAT(START_DEBIT, 1)

/*
 * Should wakeups try to preempt running tasks.
 */
SCHED_FEAT(WAKEUP_PREEMPT, 1)

/*
 * Compute wakeup_gran based on task behaviour, clipped to
 *  [0, sched_wakeup_gran_ns]
 */
SCHED_FEAT(ADAPTIVE_GRAN, 1)

/*
 * When converting the wakeup granularity to virtual time, do it such
 * that heavier tasks preempting a lighter task have an edge.
 */
SCHED_FEAT(ASYM_GRAN, 1)

/*
 * Always wakeup-preempt SYNC wakeups, see SYNC_WAKEUPS.
 */
SCHED_FEAT(WAKEUP_SYNC, 0)

/*
 * Wakeup preempt based on task behaviour. Tasks that do not overlap
 * don't get preempted.
 */
SCHED_FEAT(WAKEUP_OVERLAP, 0)

/*
 * Wakeup preemption towards tasks that run short
 */
SCHED_FEAT(WAKEUP_RUNNING, 0)

/*
 * Use the SYNC wakeup hint, pipes and the likes use this to indicate
 * the remote end is likely to consume the data we just wrote, and
 * therefore has cache benefit from being placed on the same cpu, see
 * also AFFINE_WAKEUPS.
 */
SCHED_FEAT(SYNC_WAKEUPS, 1)

/*
 * Based on load and program behaviour, see if it makes sense to place
 * a newly woken task on the same cpu as the task that woke it --
 * improve cache locality. Typically used with SYNC wakeups as
 * generated by pipes and the like, see also SYNC_WAKEUPS.
 */
SCHED_FEAT(AFFINE_WAKEUPS, 1)

/*
 * Weaken SYNC hint based on overlap
 */
SCHED_FEAT(SYNC_LESS, 1)

/*
 * Add SYNC hint based on overlap
 */
SCHED_FEAT(SYNC_MORE, 0)

/*
 * Prefer to schedule the task we woke last (assuming it failed
 * wakeup-preemption), since its likely going to consume data we
 * touched, increases cache locality.
 */
SCHED_FEAT(NEXT_BUDDY, 0)

/*
 * Prefer to schedule the task that ran last (when we did
 * wake-preempt) as that likely will touch the same data, increases
 * cache locality.
 */
SCHED_FEAT(LAST_BUDDY, 1)

/*
 * Consider buddies to be cache hot, decreases the likelyness of a
 * cache buddy being migrated away, increases cache locality.
 */
SCHED_FEAT(CACHE_HOT_BUDDY, 1)

/*
 * Use arch dependent cpu power functions
 */
SCHED_FEAT(ARCH_POWER, 1)

SCHED_FEAT(HRTICK, 0)
SCHED_FEAT(DOUBLE_TICK, 0)
SCHED_FEAT(LB_BIAS, 1)
SCHED_FEAT(LB_SHARES_UPDATE, 1)
SCHED_FEAT(ASYM_EFF_LOAD, 1)

/*
 * Spin-wait on mutex acquisition when the mutex owner is running on
 * another cpu -- assumes that when the owner is running, it will soon
 * release the lock. Decreases scheduling overhead.
 */
SCHED_FEAT(OWNER_SPIN, 1)

/*
 * Decrement CPU power based on irq activity
 */
SCHED_FEAT(NONIRQ_POWER, 1)
