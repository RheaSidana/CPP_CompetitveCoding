//Read input from STDIN. print your output to STDOUT 

importPackage(java.io);
importPackage(java.lang);

function main(){
   /* Sample code to perform I/O:
   //BufferedReader
   var stdin = new BufferedReader( new InputStreamReader(System['in']) );
   //Reading input from STDIN
   var line = stdin.readLine();  
   //Writing output to STDOUT
    System.out.println(line);  
   */
  var stdin = new BufferedReader( new InputStreamReader(System['in']) );
  var T = stdin.readLine();  
  var i;
  var arr = [];
  var res = [];
  for(i=0;i<T;i++){
     arr[i]=stdin.readLine();
  }
   for(i=0;i<T;i++){
      res[i]=0;  
     while(arr[i]>1){
        if(arr[i]%2!=0){
            //arr[i]=parseInt(arr[i]/2);
            res[i]+=parseInt(arr[i])-1;
            break;
            //arr[i]+=1;
        }
        else if(arr[i]%2==0){
            arr[i]=parseInt(arr[i]/2);
            res[i]+=parseInt(arr[i]);
        }
        if(arr[i]==1){
           break;
        }
     }
     var num = (parseInt(res[i])).toString();
      System.out.println(num);
   }
}
main();

