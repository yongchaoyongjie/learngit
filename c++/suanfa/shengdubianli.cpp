#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void DSF(int weizhi,int n,vector<int>&gift,vector<int>&book){
  if(weizhi==n+1){
    for(int i=1;i<=n;i++){
      cout<<gift[i]<<"";
    }
    cout<<endl;
    return ;
  }
  for(int i=1;i<=n;i++){
    if(book[weizhi]==0){
      book[weizhi]=i;
      book[i]=1;//当前盒子被用
      //处理下一个盒子
      DSF(weizhi+1,n,gift,book);
      book[i]=0;
    }
  }
}
void test(){
  int n;
  vector<int>gift;
  vector<int>book;
  gift.resize(n+1,0);
  gift.resize(n+1,0);
  DSF(1,n,gift,book);
}
//员工的重要性
//边界下属为空
struct emplyee{
  int id;
  int importance;
  vector<int>subordinates;
};
class solution{
  public:
    void DSF(unordered_map<int,emplyee*>&info,int &sum,int id){
      //1获取当前员工的重要度
      //2累加每一个下属的重要度
      //3DSF下属id
      //4return 累加的重要度
      sum+=info[id]->importance;
      for(const auto& e:info[id]->subordinates){
        DSF(info,sum,e);
      }
    }
    int getimportance(vector<emplyee*>emplyees,int id){
      if(emplyees.empty()){
        return 0;
      }
      unordered_map<int,emplyee*>info;
      for(const auto&e:emplyees){
        info[e->id]=e;
      }
      int sum=0;
      DSF(info,sum,id);
      return sum;
    }
};
//图像渲染
int shuzhu[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
class deal{
  void DSF(vector<vector<int>>&image,vector<vector<int>&biaoji,
      int row,int col, int sr,int sc,int oldcolor,int newcolor){
    //处理当前逻辑修改颜色,标记已经修改过
    image[sr][sc]=newcolor;
    biaoji[sr][sc]=1;
    //遍历每一种可能
    for(int k=0;k<4;k++){
      int newsr=sr+shuzhu[k][0];
      int newsc=sc+shuzhu[k][1];
      //判断是否越界
      if(newsr>=row||newsr<0){
        continue;
      }
      if(newsc>=col||newsc<0){
        continue;
      }
      //颜色符合而且之前没有被染色过,继续渲染
      if(image[newsr][newsc]==oldcolor&&image[newsr][newsc]==0){
        DSF(image,biaoji,row,col,sr,sc,oldcolor,newcolor);
      }
    }
  }
  vector<vector<int>>flood(vector<vector<int>&image,
 int sr,int sc,int newcolor){
    if(image.empt()){
      return image;
    }
    int row=image.size();
    int col=image[0].size();
    vector<vector<int>biaoji;
    biaoji.resize(row);
    for(int i=0;i<row;i++){
      biaoji[i]resize(col,0);
    }
    int oldcolor=image[sr][sc];
    DSF(image,sr,sc,oldcolor,newcolor);
    return image;
  }
};
int main(){
  test();
  return 0;
}
