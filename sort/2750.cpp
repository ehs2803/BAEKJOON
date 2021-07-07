#include<iostream>
using namespace std;
void MergeSort(int *data, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;    //�迭�� �߰� �ε��� ���ϱ�

		MergeSort(data, left, mid);      //�պκ� ���ȣ��
		MergeSort(data, mid + 1, right); //�޺κ� ���ȣ��

		int fIdx = left;    //�պκ� �迭 �����ε���
		int rIdx = mid + 1; //�޺κ� �迭 �����ε���

		int* sortArr = new int[right + 1]; //data�迭 ũ�⸸ŭ �պ��迭 �����Ҵ�
		int sIdx = left;  //�պ��迭 �����ε���

		//�պκ�,�޺κй迭 �� �Ѱ��� �պ��迭�� �պ����� ������� ��ӹݺ� 
		while (fIdx <= mid && rIdx <= right)
		{
			if (data[fIdx] <= data[rIdx])//�պκй迭�� ���� �޺κй迭 ������ ���ų� �� ������
			{
				sortArr[sIdx] = data[fIdx++];//�պ��迭�� �պκй迭�� ���� �� �պκй迭�ε���+1
			}
			else //�޺κй迭�� ���� �պκй迭 ������ ���� ��
			{
				sortArr[sIdx] = data[rIdx++];//�պ��迭�� �޺κй迭�� ���� �� �޺κй迭�ε���+1
			}

			sIdx++;//�պ��迭 �ε���+1
		}

		if (fIdx > mid) //�պκ� �迭 �պ� �Ϸ�
		{
			for (int i = rIdx; i <= right; i++, sIdx++)
			{
				sortArr[sIdx] = data[i]; //�޺κй迭 ������ �ű��
			}
		}
		else //�޺κ� �迭 �պ� �Ϸ�
		{
			for (int i = fIdx; i <= mid; i++, sIdx++)
			{
				sortArr[sIdx] = data[i];//�޺κй迭 ������ �ű��
			}
		}

		for (int i = left; i <= right; i++)
		{
			data[i] = sortArr[i]; //�����迭�� �պ��� ��� ����
		}

		delete[]sortArr;//�迭 ��ü
	}
}
int main(void){
    int num; cin>>num;
    int* arr=new int[num];
    for(int i=0;i<num;i++) cin>>arr[i];
    MergeSort(arr,0,num-1);
    for(int i=0;i<num;i++)cout<<arr[i]<<endl;
}
