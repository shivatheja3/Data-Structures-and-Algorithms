

int search(int* nums, int numsSize, int target){
    int low=0;
    int high=numsSize-1;
    int mid=(low+high)/2;
    int index=0;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target){
            index=mid;
            break;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(low>high){
        return -1;
    }
    else{
        return index;
    }
}