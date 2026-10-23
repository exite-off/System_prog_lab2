#include <iostream>
#include <vector>

using namespace std;

static bool debug = false;
const int block = 16;

void fill_array(vector<float>& v) {
    for (size_t i = 0; i < v.size(); i++)
        v[i] = (i % 100) * 0.01f;
}

float dot_product(const vector<float>& a, const vector<float>& b) {
    float sum = 0.0f;
    for (size_t i = 0; i < a.size(); i++)
        sum += a[i] * b[i];
    return sum;
}

void scale_add(vector<float>& a, const vector<float>& b, float k) {
    for (size_t i = 0; i < a.size(); i++)
        a[i] = a[i] * k + b[i];
}

int square_sum(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += i * i;
    return s;
}

bool is_prime(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0) return false;
    return true;
}

int count_primes(int limit) {
    int count = 0;
    for (int i = 0; i < limit; i++) {
        if (debug && i % 100000 == 0)
            cout << "checking " << i << endl;
        if (is_prime(i)) count++;
    }
    return count;
}

int main() {
    const int size = 1000000;
    const int reps = 300;

    vector<float> a(size), b(size);
    fill_array(a);
    fill_array(b);

    float total = 0.0f;
    long long bonus = 0;
    for (int r = 0; r < reps; r++) {
        float k = 1.0f / (block / 8);
        scale_add(a, b, k);
        total += dot_product(a, b);
        bonus += square_sum(1000) * (block * 4 / 64);
    }

    int primes = count_primes(3000000);

    cout << "total: " << total << endl;
    cout << "bonus: " << bonus << endl;
    cout << "primes: " << primes << endl;
    return 0;
}
