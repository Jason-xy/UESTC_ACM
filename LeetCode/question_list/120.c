// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

//  

// 例如，给定三角形：

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

//  

// 说明：

// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/triangle
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#define MIN(a,b) (((a) < (b)) ? (a):(b))

int findmin(int array[],int size){
    int min=INT_MAX;
    for(int i=0;i<size; i++)
    min=min<array[i]?min:array[i];
    return min;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i,j,ans;
    for(i=1;i<triangleSize;i++){
        triangle[i][i]=triangle[i-1][i-1]+triangle[i][i];
        for(j=1;j<i;j++){
            triangle[i][j]=MIN(triangle[i-1][j-1]+triangle[i][j],triangle[i-1][j]+triangle[i][j]);
        }
        triangle[i][0]=triangle[i-1][0]+triangle[i][0];
    }
    return findmin(triangle[triangleSize-1],triangleSize);
}//8ms 6.4