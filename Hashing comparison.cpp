#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
#define m 100000
#define m1 99991

int linInsert(int k, int val, int table1[m][2]){//Function for performing linear probe hashing.
//Pre-condition:k,val are not in the table
int cnt=1;
int i=0;
int slot=(k+i)%m1;//The hash is performed initially with i=0,i.e. when the initial slot is being computed.A prime number is used to compute the modulo.The same hash is used in the modified probe function as well.
while(table1[slot][0]!=NULL){//Until an empty slot is found we keep computing hash values.
cnt++;//The number of probes are recorded.This is the number of times the hash function is computed.
i++;
printf("\nThe slot %d is not empty.",slot);
slot=(k+i)%m1;
}
printf("\nkey value pair %d-%d are inserted at %d.",k,val,slot);
//Once an empty slot is found the key-value pairs are inserted.
table1[slot][0]=k;
table1[slot][1]=val;
return cnt;//The number of probes are returned.
//Post-condition:key,val are in the table
}
int modInsert(int k, int val, int table2[m][2]){//Function for performing modified probe hashing.
int cnt=1;
int i=0;
int temp=0;
int temp1=0;
int slot=(k+i)%m1;//The initial slot that the key hashes to is computed.
while(table2[slot][0]!=NULL){//Until an empty slot is found we keep computing hash values.
if(((k+i)%m1)!=slot) break;
i++;
cnt++;//The number of probes are computed.
temp=table2[slot][0];
temp1=table2[slot][1];
printf("\nThe key value pair %d-%d is being pushed out to replace the key value pair %d-%d.",temp,temp1,k,val);
table2[slot][0]=k;  // The key-value pairs are replaced by the
table2[slot][1]=val;// hashed key-value pairs.
k=temp;             // and pushed to the next hashed slot in the next iteration.
val=temp1;
slot=(k+i)%m1;
}
table2[slot][0]=k;
table2[slot][1]=val;
return cnt;//The number probes are returned.
}

int main(){
int table1[m][2];
int table2[m][2];
int k,val,slot,cnt1,cnt2;
cnt1=0;
cnt2=0;
srand(4000);
for(int i=0;i<m*0.75;i++){
k=rand()%m;//The keys
val=rand()%m;//and values are randomly generated.
cnt1=cnt1+linInsert(k,val,table1);//For each key-value pair, the number of probes are added.
cnt2=cnt2+modInsert(k,val,table2);//for both hash functions to seperate variables.
}
cnt1/=(m*0.75);//The average probes for each
cnt2/=(m*0.75);//probe function is computed.
printf("\nThe average number of probes for each key in linear probe hashing: %d",cnt1);
printf("\nThe average number of probes for each key in modified probe hashing: %d",cnt2);
return 0;
}