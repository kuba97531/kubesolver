
gcc \
 -o solver.out \
 -std=c99 \
 -Ofast \
 -funroll-loops \
 -fopenmp \
 -fno-asynchronous-unwind-tables \
 -fno-unwind-tables \
 -fschedule-insns \
 -fsched-pressure \
 -DNDEBUG \
  src/c/solver.c

  
 gcc \
 -o presenter.out \
 -std=c99 \
 -Ofast \
 -funroll-loops \
 -fopenmp \
 -fno-asynchronous-unwind-tables \
 -fno-unwind-tables \
 -fschedule-insns \
 -fsched-pressure \
 -DNDEBUG \
  src/c/presenter.c