// // #include <iostream>
// // #include "Array.hpp"

// // int main() {
// //     try {
// //         std::cout << "=== Default constructor ===" << std::endl;
// //         Array<int> a;
// //         std::cout << "Size: " << a.size() << std::endl;

// //         std::cout << "\n=== Constructor with size ===" << std::endl;
// //         Array<int> b(5);
// //         for (size_t i = 0; i < b.size(); ++i)
// //             b[i] = i * 10;
// //         for (size_t i = 0; i < b.size(); ++i)
// //             std::cout << "b[" << i << "] = " << b[i] << std::endl;

// //         std::cout << "\n=== Copy constructor ===" << std::endl;
// //         Array<int> c(b);
// //         c[0] = 999; // should not affect b
// //         std::cout << "c[0] = " << c[0] << ", b[0] = " << b[0] << std::endl;

// //         std::cout << "\n=== Assignment operator ===" << std::endl;
// //         Array<int> d;
// //         d = b;
// //         d[1] = 777; // should not affect b
// //         std::cout << "d[1] = " << d[1] << ", b[1] = " << b[1] << std::endl;

// //         std::cout << "\n=== Out of bounds test ===" << std::endl;
// //         std::cout << b[100] << std::endl; // Should throw

// //     } catch (const std::exception& e) {
// //         std::cerr << "Caught exception: " << e.what() << std::endl;
// //     }

// //     return 0;
// // }


// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        std::cout << "1. Creating default array...\n";
        Array<int> a;
        std::cout << "Size of a: " << a.size() << "\n\n";

        std::cout << "2. Creating array b with 5 elements...\n";
        Array<int> b(5);
        for (size_t i = 0; i < b.size(); ++i)
            b[i] = static_cast<int>(i * 10);
        
        std::cout << "Contents of b:\n";
        for (size_t i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << "\n\n";

        std::cout << "3. Copying array b to array c...\n";
        Array<int> c = b;
        std::cout << "Contents of c:\n";
        for (size_t i = 0; i < c.size(); ++i)
            std::cout << c[i] << " ";
        std::cout << "\n\n";

        std::cout << "4. Modifying c[0] = 999\n";
        c[0] = 999;

        std::cout << "Contents of b (should be unchanged):\n";
        for (size_t i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << "\n";

        std::cout << "Contents of c:\n";
        for (size_t i = 0; i < c.size(); ++i)
            std::cout << c[i] << " ";
        std::cout << "\n\n";

        std::cout << "5. Assigning c to a new array d...\n";
        Array<int> d;
        d = c;

        std::cout << "Contents of d:\n";
        for (size_t i = 0; i < d.size(); ++i)
            std::cout << d[i] << " ";
        std::cout << "\n\n";

        std::cout << "6. Attempting out-of-bounds access...\n";
        std::cout << d[42] << "\n"; // should throw

    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
