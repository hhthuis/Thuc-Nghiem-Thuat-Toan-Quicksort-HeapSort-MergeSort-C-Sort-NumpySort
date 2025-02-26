#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "w", stdout);
    // Có 10 dãy và mỗi dãy chứa 1 triệu phần tử
    const int num_elements = 1000000;  
    const int num_arrays = 10;

    // Khởi tạo bộ sinh số ngẫu nhiên
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0,1000000000);

    // Tạo mảng chứa 10 dãy(bằng mảng 2 chiều)
    vector<vector<int>> arrays(num_arrays);

    // Dãy thứ nhất: Thứ tự tăng dần
    for (int i = 0; i < num_elements; ++i) 
        arrays[0].push_back(dis(gen));
    sort(arrays[0].begin(), arrays[0].end());  

    // Dãy thứ hai: Thứ tự giảm dần
    for (int i = 0; i < num_elements; ++i) 
        arrays[1].push_back(dis(gen));
    sort(arrays[1].begin(), arrays[1].end(), greater<int>());  

    // 8 dãy còn lại: Trật tự ngẫu nhiên
    for (int i = 2; i < num_arrays; ++i) 
        for (int j = 0; j < num_elements; ++j) 
            arrays[i].push_back(dis(gen));
    
    // In vào input.txt        
    for (int i=0;i<num_arrays;i++)
    {
        for (int j=0;j<num_elements;j++)
            cout << arrays[i][j] << " ";
        cout << endl;
    }
    return 0;
}