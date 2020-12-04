import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * 
 * @author MeneXia (Xavi Ablaza)
 *
 */
public class TicTacToe {
	static Scanner in;
	static String[] board;
	static String turn;
	static int minIndex = 0;
	static int maxIndex = 9;
	public static int getSlotNumber(Scanner in)
	{
		int numInput;
		while(1)
		{
			
			try {
					numInput = in.nextInt();
					if (!(numInput > minIndex && numInput <= maxIndex)) {
						System.out.println("Invalid input; re-enter slot number:");
						continue;
					}else{
						return numInput;
					}
				} catch (InputMismatchException e) {
					System.out.println("Invalid input; re-enter slot number:");
					continue;
				}
		}
	}
	
	public static bool isSlotAvailable(int slot)
	{
		return (board[slot-1].equals(String.valueOf(slot));
	}
	
	public static void placeTurnAtSlot(int slot)
	{
		board[slot-1] = turn;
	}
	public static void flipTurn()
	{
		if (turn.equals("X")) {
			turn = "O";
		} else {
			turn = "X";
		}
	}
	
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		board = new String[9];
		turn = "X";
		String winner = null;
		populateEmptyBoard();

		System.out.println("Welcome to 2 Player Tic Tac Toe.");
		System.out.println("--------------------------------");
		printBoard();
		System.out.println("X's will play first. Enter a slot number to place X in:");

		while (winner == null) {
			int numInput = getSlotNumber(in);
			if(isSlotAvailable(numInput))
			{
				placeTurnAtSlot(numInput);
				flipTurn();				
				printBoard();
				winner = checkWinner();
			} else {
				System.out.println("Slot already taken; re-enter slot number:");
				continue;
			}
		}
		if (winner.equalsIgnoreCase("draw")) {
			System.out.println("It's a draw! Thanks for playing.");
		} else {
			System.out.println("Congratulations! " + winner + "'s have won! Thanks for playing.");
		}
	}

	static String checkWinner() {
		for (int a = 0; a < 8; a++) {
			String line = null;
			switch (a) {
			case 0:
				line = board[0] + board[1] + board[2];
				break;
			case 1:
				line = board[3] + board[4] + board[5];
				break;
			case 2:
				line = board[6] + board[7] + board[8];
				break;
			case 3:
				line = board[0] + board[3] + board[6];
				break;
			case 4:
				line = board[1] + board[4] + board[7];
				break;
			case 5:
				line = board[2] + board[5] + board[8];
				break;
			case 6:
				line = board[0] + board[4] + board[8];
				break;
			case 7:
				line = board[2] + board[4] + board[6];
				break;
			}
			if (line.equals("XXX")) {
				return "X";
			} else if (line.equals("OOO")) {
				return "O";
			}
		}

		for (int a = 0; a < 9; a++) {
			if (Arrays.asList(board).contains(String.valueOf(a+1))) {
				break;
			}
			else if (a == 8) return "draw";
		}

		System.out.println(turn + "'s turn; enter a slot number to place " + turn + " in:");
		return null;
	}

	static void printBoard() {
		System.out.println("/---|---|---\\");
		System.out.println("| " + board[0] + " | " + board[1] + " | " + board[2] + " |");
		System.out.println("|-----------|");
		System.out.println("| " + board[3] + " | " + board[4] + " | " + board[5] + " |");
		System.out.println("|-----------|");
		System.out.println("| " + board[6] + " | " + board[7] + " | " + board[8] + " |");
		System.out.println("/---|---|---\\");
	}

	static void populateEmptyBoard() {
		for (int a = 0; a < 9; a++) {
			board[a] = String.valueOf(a+1);
		}
	}
}