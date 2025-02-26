#include <bits/stdc++.h>
using namespace std;

// QuickSort
void quickSort(vector<int>& a, int l, int r) {
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j) {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) 
		{
			swap(a[i], a[j]); 
			i++;j--;
		}
	}
	if (i < r) quickSort(a, i, r);
	if (l < j) quickSort(a, l, j);
}

// HeapSort
void heapify(vector<int>& a, int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(vector<int>& a){
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// Merge Sort
void merge(vector<int>& a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];i++;
        }
        else 
        {
            a[k] = R[j];j++;
        }
        k++;
    }

    while (i < n1) 
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& a, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

// C++ sort
void sortCpp(vector<int> &a)
{
    sort(a.begin(),a.end());
}

// Chạy thực nghiệm
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	vector<vector<int>> arrays(10);
	const int elements=1000000;
	for (int i=0;i<10;i++) 
	{
		for (int j=0;j<1000000;j++)
		{
			int x;cin >> x;
			arrays[i].push_back(x);
		}
	}
	//QuickSort
	for (int i = 0; i < 10; ++i) {
        auto start = chrono::high_resolution_clock::now();
        quickSort(arrays[i], 0, elements - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "QuickSort - Dãy " << i + 1 << ": " << duration.count() << " giây" << endl;
    }
	cout << endl;
	// HeapSort
	for (int i = 0; i < 10; ++i) {
        auto start = chrono::high_resolution_clock::now();
        heapSort(arrays[i]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "HeapSort - Dãy " << i + 1 << ": " << duration.count() << " giây" << endl;
    }
	cout << endl;
	// Merge Sort
	for (int i = 0; i < 10; ++i) {
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arrays[i], 0, elements - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "MergeSort - Dãy " << i + 1 << ": " << duration.count() << " giây" << endl;
    }
	cout << endl;
	// Cpp Sort
	for (int i = 0; i < 10; ++i) {
        auto start = chrono::high_resolution_clock::now();
        sortCpp(arrays[i]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "CppSort - Dãy " << i + 1 << ": " << duration.count() << " giây" << endl;
    }
	return 0;
	
}
