/*平面上有若干个点，我们需要用一些线段来将这些点连接起来使
任意两个点能够通过一系列的线段相连，给出所有点的坐标，
求一种连接方式使 所有线段的长度和最小，求该长度和

sample in:
3
1.0 1.0
2.0 2.0
2.0 4.0

sample out:
3.41

 */

#include "stdio.h"
#include "math.h"
#include "algorithm"

using namespace std;

#define SIZE 1001

struct Edge{
    int start;
    int end;
    float weight;

    bool operator < (const Edge & other) const{
        return weight < other.weight;
    }
}edge[SIZE];

struct Point{
    float x;
    float y;

    float  getdistance(Point end){
        float tmp;
        tmp = (end.x - x) * (end.x - x)  +  (end.y - y) * (end.y - y) ;
        return sqrt(tmp);
    }
}point[SIZE];

int Tree[SIZE];
float total = 0;

void clear(){
    for (int i = 0; i <SIZE ; ++i) {
        Tree[i] = -1;
    }
    total = 0;
}

int findroot( int x){
    if(Tree[x] == -1) return x;
    else{
        int root = findroot(Tree[x]);
        Tree[x] = root;
        return root;
    }
}

int main(){
    int line;
    scanf("%d", &line);

    for (int count = 0; count < line; count++) {  //
        scanf("%f %f",&point[count].x, &point[count].y);
    } //input done

    //make up edges , the number of edges should connect all points except itself
    int count_edge=0;
    for (int i = 0; i < line ; ++i)
        for (int j = i+1; j < line  ; ++j) {
            edge[count_edge].start = i;
            edge[count_edge].end = j;
            edge[count_edge].weight = point[i].getdistance(point[j]);

            count_edge ++;
        }

    //sort edge by weight
    sort(edge, edge+count_edge);

    clear();
    for (int k = 0; k < count_edge; ++k) {
        int roota= findroot(edge[k].start);
        int rootb= findroot(edge[k].end);

        if(roota != rootb){
            Tree[roota] = rootb;
            total += edge[k].weight;
        }

    }

    printf("%.2f\n",total); //no need to use long float

    return 0;
}
