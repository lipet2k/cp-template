#include <vector>
#include <iostream>

using namespace std;

void merge(int arr[], int const left, int const mid, int const right)
{

        int const arr_one = mid - left + 1;
        int const arr_two = right - mid;

        int left_arr[arr_one];
        int right_arr[arr_two];

        for (int i = 0; i < arr_one; ++i)
                left_arr[i] = arr[left + i];
        for (int i = 0; i < arr_two; ++i)
                right_arr[i] = arr[mid + i + 1];

        int index_one = 0;
        int index_two = 0;

        int indexOfMerged = left;

        while (index_one < arr_one && index_two < arr_two)
        {
                if (left_arr[index_one] <= right_arr[index_two])
                {
                        arr[indexOfMerged] = left_arr[index_one];
                        index_one++;
                }
                else
                {
                        arr[indexOfMerged] = right_arr[index_two];
                        index_two++;
                }
                indexOfMerged++;
        }

        while (index_one < arr_one)
        {
                arr[indexOfMerged] = left_arr[index_one];
                index_one++;
                indexOfMerged++;
        }
        while (index_two < arr_two)
        {
                arr[indexOfMerged] = right_arr[index_two];
                index_two++;
                indexOfMerged++;
        }
}

void mergeSort(int arr[], int const begin, int const end)
{
        if (begin >= end)
        {
                return;
        }

        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
}

int partition(int arr[], int low, int high)
{
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high; ++j)
        {
                if (arr[j] < pivot)
                {
                        i++;
                        swap(arr[i], arr[j]);
                }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
        if (low < high)
        {
                int pi = partition(arr, low, high);
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
        }
}

vector<bool> sieve(int n)
{
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= n; ++i)
        {
                if (is_prime[i] && (long long)i * i <= n)
                {
                        for (int j = i * i; j <= n; j += i)
                        {
                                is_prime[j] = false;
                        }
                }
        }
        return is_prime;
}

int bin_search(int arr, int target, int n) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Majority voting algorithm if the majority element is
// more than floor(n/2) occurances
int boyer_moore(int arr[]) {
    int count = 0;
    int candidate = 0;

    for (int num: arr) {
        if (count == 0)
            candidate = num;

        if (num == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}



int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int arr[10];

        for (int i = 0; i < 10; ++i)
        {
                arr[i] = 20 - i;
        }

        mergeSort(arr, 0, 9);

        for (int i : arr)
        {
                cout << i << " ";
        }
        return 0;
}
