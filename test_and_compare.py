import os
import math
import sys


# Names of files
cons_results = 'results/consistent_results.txt'
paral_results = 'results/parallel_results.txt'
cons_prog = 'consistent_program'
paral_prog = 'parallel_program'


def run_programs(number_of_tests):
    for i in range(number_of_tests):
        os.system('./build/{}'.format(cons_prog))

    for i in range(1, 5):
        for j in range(number_of_tests):
            os.system('./build/{} {}'.format(paral_prog, i))
    for i in range(1, 5):
        for j in range(number_of_tests):
            os.system('./build/{} {}'.format(paral_prog, 10**i))


def parse_files(number_of_tests):
    def parse_one_try(lines):
        current_number_of_solutions = int(lines[-2].strip('\n').split(' ')[-1])
        current_time = int(lines[-1].split(' ')[-2])
        return current_number_of_solutions, current_time

    def parse_and_check_consistent(number_of_solutions, lines):
        current_number_of_solutions, current_time = parse_one_try(lines)
        assert current_number_of_solutions == number_of_solutions, 'Number of solutions does not match'
        try:
            if results['consistent'] > current_time:
                results['consistent'] = current_time
        except TypeError:
            results['consistent'] = current_time

    def parse_and_check_parallel(number_of_solutions, lines):
        current_number_of_solutions, current_time = parse_one_try(lines)
        assert current_number_of_solutions == number_of_solutions, 'Number of solutions does not match'
        number_of_threads = int(lines[0].strip('\n').split(' ')[-1])
        try:
            if results['parallel'][number_of_threads] > current_time:
                results['parallel'][number_of_threads] = current_time
        except KeyError:
            results['parallel'][number_of_threads] = current_time

    results = {'consistent': None,
               'parallel': {}}

    with open(cons_results, 'r') as file:
        data = file.readlines()
        number_of_solutions = int(data[0].strip('\n').split(' ')[-1])
        for i in range(number_of_tests):
            parse_and_check_consistent(number_of_solutions, data[i * 2: i * 2 + 2])

    with open(paral_results, 'r') as file:
        data = file.readlines()
        for i in range(8 * number_of_tests):
            parse_and_check_parallel(number_of_solutions, data[i * 3: i * 3 + 3])

    return results


def plot_charts(results):
    import matplotlib.pyplot as plt

    res = results['parallel']
    x = list(range(1, 5))
    y1 = [res[i] for i in x]
    y2 = [math.log10(res[10**i]) for i in x]
    plt.xlim((0, 5))
    plt.plot(x, y1)
    plt.xlabel('number of threads')
    plt.ylabel('total time (microseconds) of processing')
    plt.savefig('1-4_parl_res.png')
    plt.clf()
    plt.plot(x, y2)
    plt.xlabel('10^x number of threads')
    plt.ylabel('10^y total time (microseconds) of processing')
    plt.savefig('10-10000_parl_res.png')


def main():
    # Clearing files
    cons_file = open(cons_results, 'w')
    cons_file.close()
    par_file = open(paral_results, 'w')
    par_file.close()

    # Default values
    to_plot = False
    number_of_tests = 1000

    # Looking for arguments
    if len(sys.argv) > 1:
        to_plot = sys.argv[1].strip().lower() == 'yes'
        if len(sys.argv) > 2:
            try:
                number_of_tests = int(sys.argv[2])
            except ValueError:
                print('Bad argument.\nShould be an integer representing number of tests.')
                return -1

    # Running programs
    run_programs(number_of_tests)

    # Parsing results
    results = parse_files(number_of_tests)

    # Printing results
    print('Total time of processing (in microseconds).\nConsistent program: {}\nParallel programs:\n'
          .format(results['consistent']) +
          '\n'.join(['Number of threads: {}, time: {}'.format(n, t) for n, t in results['parallel'].items()]))

    # Plotting results if required
    if to_plot:
        plot_charts(results)


if __name__ == "__main__":
    main()
