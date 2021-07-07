#include<iostream>
using namespace std;
void MergeSort(int *data, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;    //배열의 중간 인덱스 구하기

		MergeSort(data, left, mid);      //앞부분 재귀호출
		MergeSort(data, mid + 1, right); //뒷부분 재귀호출

		int fIdx = left;    //앞부분 배열 시작인덱스
		int rIdx = mid + 1; //뒷부분 배열 시작인덱스

		int* sortArr = new int[right + 1]; //data배열 크기만큼 합병배열 동적할당
		int sIdx = left;  //합병배열 시작인덱스

		//앞부분,뒷부분배열 중 한개라도 합병배열에 합병되지 않은경우 계속반복 
		while (fIdx <= mid && rIdx <= right)
		{
			if (data[fIdx] <= data[rIdx])//앞부분배열의 값이 뒷부분배열 값보다 같거나 더 작을때
			{
				sortArr[sIdx] = data[fIdx++];//합병배열에 앞부분배열값 저장 후 앞부분배열인덱스+1
			}
			else //뒷부분배열의 값이 앞부분배열 값보다 작을 때
			{
				sortArr[sIdx] = data[rIdx++];//합병배열에 뒷부분배열값 저장 후 뒷부분배열인덱스+1
			}

			sIdx++;//합병배열 인덱스+1
		}

		if (fIdx > mid) //앞부분 배열 합병 완료
		{
			for (int i = rIdx; i <= right; i++, sIdx++)
			{
				sortArr[sIdx] = data[i]; //뒷부분배열 나머지 옮기기
			}
		}
		else //뒷부분 배열 합병 완료
		{
			for (int i = fIdx; i <= mid; i++, sIdx++)
			{
				sortArr[sIdx] = data[i];//뒷부분배열 나머지 옮기기
			}
		}

		for (int i = left; i <= right; i++)
		{
			data[i] = sortArr[i]; //원본배열에 합병한 결과 저장
		}

		delete[]sortArr;//배열 해체
	}
}
int main(void){
    int num; cin>>num;
    int* arr=new int[num];
    for(int i=0;i<num;i++) cin>>arr[i];
    MergeSort(arr,0,num-1);
    for(int i=0;i<num;i++)cout<<arr[i]<<endl;
}
