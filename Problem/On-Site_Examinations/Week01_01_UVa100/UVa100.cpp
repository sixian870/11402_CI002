/*
UVa100
��J�_�l�Ƹ򵲧���
�C�ӼƦr�g���`�� if(%2==0)->/2; if(%2==1)->*3+1; if(==1)break;
���O�p��`�����ƥB��X�̤j�� 
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n1,n2;
	
	while(cin>>n1>>n2){ //��(����)�ŦX�N���_���� 
	
		int max_count=0;
		
		for(int i=min(n1,n2);i<=max(n1,n2);i++){
			
			int temp=i;
			int count=1;
			
			while(temp!=1){
				
				if(temp%2==0){
					temp=temp/2;
				}
				else{	
					temp=3*temp+1;
				}
				count++;
			} 
			/*if(i==1){
				break;
			}*/
			//�� while�~�୫�ư���
			if(count>max_count){
				max_count=count;
			}
		}
		cout<<n1<<" "<<n2<<" "<<max_count<<endl;
	}
	return 0;
} 
