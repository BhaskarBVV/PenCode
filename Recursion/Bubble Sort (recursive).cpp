#include <iostream>
using namespace std;
// in half recursive method there is one for loop while in complete recursive manner there is no loop.

void bubble_sort_half_recursive(int a[], int n)
{
    // in Each recursive call we have to sort (n-1) elements 
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
    }
    bubble_sort_half_recursive(a, n - 1);
}
void bubble_sort_complete_recursive(int a[], int j, int n)
{
    if (n == 1)
        return;
    if (j == n - 1)
    {
        // In the given pass when the (j) pointer reaches to end i.e. equal to (n-1)th index, than pass is said to be complete
        // next pass is called when for remaining first (n-1) from first (n) elements.
        // for beginning of each pass (j) is set to (0);
        // number of elements will be reduced by one for the next pass;
        return bubble_sort_complete_recursive(a, 0, n - 1);
    }
    // Here also we are doing same thing but without loop.
    // When 
    if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    bubble_sort_complete_recursive(a, j + 1, n);
    return;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // bubble_sort_half_recursive(a, n);
    bubble_sort_complete_recursive(a, 0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
