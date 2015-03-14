#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <fstream>

// Fibonacci definitions from
// http://planet.jboss.org/post/fibonacci_sequence_with_and_without_recursion

int fibNonRecurse(int n)
{
    if(n <= 1)
    {
        return n;
    }
    int fib = 1;
    int fibPrev = 1;
    for(int i = 2; i < n; ++i)
    {
        int temp = fib;
        fib += fibPrev;
        fibPrev = temp;
    }

    return fib;
}

int fibRecurse(int n){

    if(n <= 1){
        return n;
    }else{
        return fibRecurse(n-1) + fibRecurse(n-2);
    }
}

double rfactorialNonTail(int n) {
    if(n == 1)
        return 1;
    else
        return n * rfactorialNonTail(n-1);
}

// Factorial definitions from assignment

double rfactorialTailHelper(double n, double result)
{
    if(n == 1)
        return result;
    else
        return rfactorialTailHelper(n-1, n*result);
}

double rfactorialTail(double n)
{
    return rfactorialTailHelper(n, 1);
}



int main()
{
    std::ofstream fibRecurseFile;
    std::ofstream fibNonRecurseFile;
    std::ofstream facNonTailFile;
    std::ofstream facTailFile;

    fibRecurseFile.open("results-fib-recurse.csv");
    fibNonRecurseFile.open("results-fib-nonrecurse.csv");
    facNonTailFile.open("results-fac-nontail.csv");
    facTailFile.open("results-fac-tail.csv");

    fibRecurseFile << "iteration,value,time\n";
    fibNonRecurseFile << "iteration,value,time\n";
    facNonTailFile << "iteration,value,time\n";
    facTailFile << "iteration,value,time\n";



    for(int i = 1; i < 30; i++) {
        int fibNonRecurseVal;

        std::clock_t t;
        t = clock();
        fibNonRecurseVal = fibNonRecurse(i);
        t = clock() - t;
        std::cout << fibNonRecurseVal << std::endl;
        std::cout << "Total time was " << std::fixed << std::setprecision(10) << t << " clicks. (Fib non-recursive)" << std::endl;
        fibNonRecurseFile << std::fixed << std::setprecision(10) << i << "," << fibNonRecurseVal << "," << t << "\n";

        int fibRecurseVal;
        std::clock_t u;
        u = clock();
        fibRecurseVal = fibRecurse(i);
        u = clock() - u;
        std::cout << fibRecurseVal << std::endl;
        std::cout << "Total time was " << std::fixed << u << " clicks. (Fib recursive)" << std::endl;
        fibRecurseFile << std::fixed << std::setprecision(10) << i << "," << fibRecurseVal << "," << u << "\n";

        double facNonTail;
        std::clock_t v;
        v = clock();
        facNonTail = rfactorialNonTail(i);
        v = clock() - v;
        std::cout << facNonTail << std::endl;
        std::cout << "Total time was " << std::fixed << t << " clicks. (Fac Non-Tail recursive)" << std::endl;
        facNonTailFile << std::fixed << std::setprecision(10) << i << "," << facNonTail << "," << v << "\n";

        double facTail;
        std::clock_t w;
        w = clock();
        facTail = rfactorialTail(static_cast<double>(i));
        w = clock() - w;
        std::cout << facTail << std::endl;
        std::cout << "Total time was " << std::fixed << w << " clicks. (Fac Tail recursive)" << std::endl;
        facTailFile << std::fixed << std::setprecision(10) << i << "," << facTail << "," << w << "\n";

    }

    facTailFile.close();
    facNonTailFile.close();
    fibNonRecurseFile.close();
    fibRecurseFile.close();

    return 0;
}

