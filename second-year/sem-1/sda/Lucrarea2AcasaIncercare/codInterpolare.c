// //PROTOTIP
// int searchEl(int x, Job *vector, int nrElem) {
//     int left=0;
//     int right=nrElem-1;
//     int mid;
//     int counter = 0;

//     do {
//         //mid = right + ((x-vector[right].code)*(left-right))/(vector[left].code-vector[right].code);
        
//         // mid = left + ((x-vector[left].code)*(right-left))/(vector[right].code-vector[left].code);
//         // if(mid<0)mid*=-1;  
//         //mid = right - (x-vector[right].code)*(right-left)/(vector[left].code-vector[right].code);
        
//         mid = left + ((right-left)/(vector[right].code-vector[left].code))*(x-vector[left].code);
//         counter++;
//         printf("mid: %d\n",mid);

//         if(x > vector[mid].code) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }while((left<=right) && (vector[mid].code!=x) && (vector[right].code!=vector[left].code)
//             && (x<=vector[left].code) && (x>=vector[right].code));
    
//     printf("%d\n",counter);

//     if(vector[mid].code == x) {
//         return mid;
//     } else {
//         return -1;
//     }

// }