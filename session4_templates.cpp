// C++ 101 de chillin - Sesión 4
// https://youtu.be/2MfsjLpTIZc
// https://www.twitch.tv/videos/966204946

#include <cstdio>
#include <vector>
#include <variant>

/*int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}*/

// template <class T>
/*template <typename T>
T sum(T a, T b) {
     return a + b;
}*/

template <typename T, typename U>
T sum(T a, U b) {
    return a + b;
}

int main(int argc, char *argv[])
{
    printf("Templates\n");
    printf("sum ints: %d\n", sum(1, 2));
    printf("sum floats: %f\n", sum(1.0f, 2.0f));
    sum(1, 2.0f);

    std::vector<int> myVector;
    myVector.emplace_back(1);
    myVector.emplace_back(2);
    myVector.emplace_back(3);
    myVector.emplace_back(4);
    myVector.emplace_back(5);

    for (auto value : myVector) {
        printf("%d, ", value);
    }
    printf("\n");

    std::vector<std::variant<int, double>> myVariantVector;
}
