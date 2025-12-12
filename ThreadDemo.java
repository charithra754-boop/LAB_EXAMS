public class ThreadDemo {
    public static void main(String[] args) {
        System.out.println("--- 🧵 Threading Demo 🧵 ---");
        // Fun Fact: The Apollo 11 Guidance Computer was one of the first to use a form of multithreading (called cooperative multitasking) to land on the moon!
        
        PrimeThread t1 = new PrimeThread();
        DivisibleThread t2 = new DivisibleThread();
        
        t1.start();
        t2.start();
    }
}

class PrimeThread extends Thread {
    public void run() {
        System.out.println("[PrimeThread] Started...");
        for (int i = 1; i <= 100; i++) {
            if (isPrime(i)) {
                System.out.println("Prime: " + i);
                try {
                    Thread.sleep(500); // 0.5 seconds
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }
        System.out.println("[PrimeThread] Finished!");
    }

    private boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

class DivisibleThread extends Thread {
    public void run() {
        System.out.println("[DivisibleThread] Started...");
        for (int i = 1; i <= 100; i++) {
            // Divisible by 2, 4, & 6.
            // LCM(2, 4, 6) = 12.
            if (i % 2 == 0 && i % 4 == 0 && i % 6 == 0) {
                System.out.println("Divisible (2,4,6): " + i);
                try {
                    Thread.sleep(500); // 0.5 seconds
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }
        System.out.println("[DivisibleThread] Finished!");
    }
}
