public class converseType {
    public static void main(String[] args){
        int un = 1;
        String deux = "2";
        System.out.println("Resutat = "+(un + Integer.parseInt(deux))); // Integer.parseInt() converti un String en Integer (int)
        System.out.println("de : "+ String.valueOf(un) + " + " + deux); // et là l'inverse un Integer en String
    }
}
