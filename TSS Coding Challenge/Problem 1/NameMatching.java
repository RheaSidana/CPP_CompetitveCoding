/* Read input from STDIN. Print your output to STDOUT*/

import java.io.*;
import java.util.*;
public class CandidateCode {
   static ArrayList<String> removeSpecialWords(String name){
      String[] arr = name.split(" ");
      ArrayList<String> res = new ArrayList<String>();
      int i=0;
      for(String s: arr){
         if(s.equalsIgnoreCase("Mr.") || s.equalsIgnoreCase("Ms.") || s.equalsIgnoreCase("Mrs.") || s.equalsIgnoreCase("Shri."))
            continue;
         else{
            res.add(s.toLowerCase());
            i++;
         }
      }
      return res;
   }

   static Set<String> isEqual(ArrayList<String> n1, ArrayList<String> n2){
      Set<String> nameSet = new HashSet<String>();
      nameSet.addAll(n1);
      nameSet.addAll(n2);
      return nameSet;
   }

   static Set<String> oneWordDiffSpell(Set<String> nameSet){
      String sameName="";
      for(String s: nameSet){
         if(s.contains("ee")){
            sameName = s.replace("ee","i");
            if(nameSet.contains(sameName)){
               nameSet.remove(sameName);
               break;
            }
         }
         else if(s.contains("ph")){
            sameName = s.replace("ph","f");
            if(nameSet.contains(sameName)){
               nameSet.remove(sameName);
               break;
            }
         }
         else if(s.contains("ie")){
            sameName = s.replace("ie","y");
            if(nameSet.contains(sameName)){
               nameSet.remove(sameName);
               break;
            }
         }
         else if(s.contains("ie")){
            sameName = s.replace("ie","ee");
            if(nameSet.contains(sameName)){
               nameSet.remove(sameName);
               break;
            }
         }
         else if(s.contains("ksh")){
            sameName = s.replace("ksh","x");
            if(nameSet.contains(sameName)){
               nameSet.remove(sameName);
               break;
            }
         }
      }
      return nameSet;
   }

   static Set<String> initialsPresent(Set<String> nameSet){
      int singleEle=0;
      while(true){
      for(String s : nameSet){
         if(s.length()>2){
            String str=""+s.charAt(0);
            if(nameSet.contains(str)){
               nameSet.remove(str);
               singleEle-=1;
               break;
            }
         }
         else{
            singleEle+=1;
         }
      }
      if(singleEle!=0){
         singleEle=0;
      }
      else if(singleEle==0)break;
      }
      return nameSet;
   }

   static boolean endProgram(Set<String> nameSet,ArrayList<String> nameArr1, ArrayList<String> nameArr2){
      if(nameSet.size() == nameArr1.size() || nameSet.size() == nameArr2.size()){
         return true;
      }
      return false;
   }

   static boolean diffBonded(ArrayList<String> nameArr1, ArrayList<String> nameArr2){
      String str1="";
      String str2="";
      for(String s: nameArr1){
         str1+=s;
      }
      for(String s: nameArr2){
         str2+=s;
      }
      if(str1.equals(str2))return true;
      //else return diffLogic(str1,str2);
      return false;
   }

   static boolean diffLogic(String str1,String str2){
      int len,i;
      int isPart=0,isNotPart1=0,isNotPart2=0;
      char c1,c2;
      if(str1.length()>=str2.length())len=str1.length();
      else len=str2.length();
      for(i=0;i<len;i++){
         if(i<str1.length())
            c1=str1.charAt(i);
         else{
            isNotPart2+=str2.length()-i+1;
            break;
         }

         if(i<str2.length())
            c2=str2.charAt(i);
         else{
            isNotPart1+=str1.length()-i+1;
            break;
         }

         if(c1==c2)isPart++;
         else{
            isNotPart1++;
            isNotPart2++;
         }
      }
      //i++;
      //isNotPart1=str1.length()-i;
      //isNotPart2=str2.length()-i;

      if(isPart>isNotPart1 || isPart>isNotPart2)
         return true;
      return false;
   }

   public static void main(String args[] ) throws Exception {
      String name1,name2;
      Scanner in = new Scanner(System.in);

      name1=in.nextLine();
      name2=in.nextLine();

      ArrayList nameArr1 = removeSpecialWords(name1);
      ArrayList nameArr2 = removeSpecialWords(name2);

      boolean endProgram=false;

      Set<String> nameSet = isEqual(nameArr1,nameArr2);

      if(endProgram(nameSet,nameArr1,nameArr2)){
         System.out.println("Match");   
      }
      else {
         nameSet = initialsPresent(nameSet);
         if(endProgram(nameSet,nameArr1,nameArr2)){
            System.out.println("Match");   
         }
         else{
            nameSet = oneWordDiffSpell(nameSet);
            if(endProgram(nameSet,nameArr1,nameArr2)){
               System.out.println("Match");   
            }
            else{
               if(diffBonded(nameArr1,nameArr2)){
                  System.out.println("Match");   
               }
               else{
                  if(diffLogic(name1.toLowerCase(),name2.toLowerCase())){
                     System.out.println("Match");
                  }
                  else System.out.println("No Match");
               }
            }
         }
      }
   }
}
