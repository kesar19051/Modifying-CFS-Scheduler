# Modifying-CFS-Scheduler
Modifying the scheduler using a system call called rtnice

Modifying the scheduler in such a way that when
everytime a process is selected through the RB-tree, you need to compare
to all other process with soft-realtime requirements and see which one of those
require the CPU more urgently than the one selected through the regular RBtree. The one that urgently requires CPU time need to be scheduled before the
one selected through CFS
