# Parallel solutions

Counting number of non-trivial solutions for equation **w<sup>2</sup> + x<sup>2</sup> = y<sup>2</sup> + z<sup>2</sup>**.
<br /> All values in range [1; 200]


## Compilation

Creating new working directory: <br />
`mkdir build`

Go to working directory: <br />
`cd build`

Compiling cpp files: <br />
`cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..`  <br />
`make`

## Running programs

Run consistent program: <br />
`./consistent_program`
All result will be saved in **../results/consistent_results.txt**

Run parallel program: <br />
`./parallel_program <number_of_threads>` <br />
Where **<number_of_threads>** -- number of threads, in which current program will work. <br /> Defalt - 4 threads.
All result will be saved in **../results/parallel_results.txt**

## Running test script

Go to upper directory: <br />
`cd ..`

Run test: <br /> 
`python3 test_and_compare.py <plot_results> <number_of_tests>` <br />
Where **<plot_results>** ('_yes_'/'_no_') -- Do you want to plot results. Defalt - no. (If yes -- you need to install _matplotlib_).
**<number_of_tests>** -- Number of test required for each option.

## Results

Number of tests -- 1000.

<br />
Total time of processing **consistent program** -- 613422 microseconds.
<br />

Number of threads: | 1 | 2 | 3 | 4
---|---|---|---|---
**Total time of processing (microseconds):** | 571210 | 535880 | 488610 | 427896

![picture alt](https://github.com/satl-it-e/parallel_solutions/blob/master/1-4_parl_res.png)


<br /> <br />

Number of threads: | 10 | 100 | 1000 | 10000
---|---|---|---|---
**Total time of processing (microseconds):** | 320293 | 115170 | 3749 | 37294

![picture alt](https://github.com/satl-it-e/parallel_solutions/blob/master/10-10000_parl_res.png)
