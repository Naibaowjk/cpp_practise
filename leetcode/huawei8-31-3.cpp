/*
第三题：高速公路休息站充电规划 （部分AC）
题目描述
张三购买了一辆续航里程数达1000公里的某自动驾驶新能源车。 某一天车辆充满电后，需从甲城出发前往距离D公里远的乙城，全程走高速。

车载导航提示沿途有N个休息站均可提供充电服务，各休息站均可实时提供当前充电排队时间(小时)。
请协助规划时间最优的休息站充电方案，返回最短的旅行用时。

为方便计算，高速上的行驶速度固定为100公里/小时。 规划时可不必考虑保留安全续航里程数，
汽车可以将电完全用光，1000公里续航的汽车按100公里/小时，可以开10个小时。
每次充电时间固定为1小时，完成后电量充满。各站点充电排队时间不会变化，充电排队过程不耗电。

输入描述

第一行表示甲乙两城的距离D，单位为公里;
第二行表示沿途的休息站数量N;
第三行起，每行2个数据，分别表示休息站距离甲城的距离，以及充电排队所需时间(小时)，(各休息站按离从近到远排序)
0<=D<=1000000，D是100的整数倍
0<=N<=10000
*/

/*
解释:
最佳方案：只在第3个休息站(位置1000)进行充电
1500公里的行程耗时:15小时
充电排队0小时，充电1小时
最快旅程总计花费16小时

其他方案:在第2个休息站(位置600)进行充电，总计花费17小时
其他方案:在第2个休息站(位置600)和第4个休息站(位置1200)进行充电，总计花费19小时

思路
利用动态规划+加回退搜索
把起始点设为0，每次到达一个新的站点，便进行回退搜索，一直搜索到1000公里以内且距离最远的充电站点k，
然后从k站点开始遍历，一直遍历到当前站点，找到最短到达当前站点的时间，然后保存到当前站点的时间数组ans中，不断循环遍历，最终遍历到终点。
*/


#define DEBUG 1
#if DEBUG
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	int n, m;
	//参数输入
	cin >> n;
	cin >> m;

	//初始化站点数组，将起点和终点也纳入数组中
	vector<vector<int>> f(m+2, vector<int>(2));

	//起点的距离和等待时间都设为0
	f[0][0] = 0;
	f[0][1] = 0;
	//终点的距离设为n，等待时间设为0
	f[m+1][0] = n;
	f[m+1][1] = 0;

	//开始加入各个站点
	for (int i = 1; i < m+1; i++) {
		cin >> f[i][0];
		cin >> f[i][1];
		cout << f[i][0] << ' ';
		cout << f[i][1] << ' ';

	}

	//初始化到达站点的时间，将起点和终点也纳入数组中
	vector<int> ans(m + 2);
	ans[0] = 0;

	//开始计算各个站点
	for (int i = 1; i < m + 2; i++) {
		//将所有距离在1000以内的站点找出来
		int k = i - 1;
		while (k > 0 && (f[i][0] - f[k][0] < 1000)){
			k--;
		}
		//这里除了起始站点以外，多超了一个站点，因此k需要加一
		if (k != 0) {
			k++;
		}
		//对每个可以直接到达的站点进行遍历，找出最小的时间站点
		int min_time = INT_MAX;
		for (; k < i; k++) {
			int cur_time = (f[i][0] - f[k][0]) / 100 + ans[k] + f[i][1];
			if (k != 0) {
				cur_time++;
			}
			min_time = min(min_time, cur_time);
		}

	}
	getchar();
	cout << ans[m+1] << endl;

	getchar();

}
// vx公众号关注TechGuide 实时题库 闪电速递