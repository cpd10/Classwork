
public class LexAnalyzer 
{
	private String str;
	private char curr;
	private int index;
	
	/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	||																						||
	||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	
	public LexAnalyzer (String s)
	{
		str = s;
	}
	
	/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	||																						||
	||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	
	public void printTokenList()
	{
		index = 0;
		String sub = str.trim();
		if(sub.matches(""))
			System.out.println("EMPTY TOKEN LIST");
		else
		{
			curr = str.charAt(index);
			while(index < str.length())
				print_next_token();
		}
	}
	
	/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	||																						||
	||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	
	private void print_next_token()
	{
		int beg = index;
		char next;
		if(index == str.length() - 1)
			next = str.charAt(index);
		else	
			next = str.charAt(index + 1);
		
	//If in the set {( , ) , + , - , / , ; , =}
	///////////////////////////////////////////
		if(curr == '(' || curr == ')' || curr == '+' || curr == '-' || curr == '*' || curr == '/' || curr == ';' || curr == '=' || curr == ' ')
			switch(curr)
			{
				case '(':	System.out.println("LEFTPAREN");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case ')':	System.out.println("RIGHTPAREN");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case '+':	System.out.println("PLUS");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case '-':	System.out.println("MINUS");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case '*':	System.out.println("TIMES");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case '/':	System.out.println("DIVIDE");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case ';':	System.out.println("SEMICOLON");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case '=':	System.out.println("ASSIGNMENT");
							if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
				case ' ':	if(index <= str.length() - 1)
							{
								index++;
								if(index == str.length())
									break;
								curr = str.charAt(index);
							}
							break;
			}//end switch
		//end if

	
	//if current character is a digit
	////////////////////////////////
		else if(curr >= '0' && curr <= '9')
		{
			
			do
			{
				//read for more digits or one decimal point
				if(Character.isDigit(next))
				{
					index++;
					if(index == str.length())
					{
						System.out.println("INTEGER " + str.substring(beg, index));
						break;
					}
					
					curr = str.charAt(index);
					
					if(index == str.length() - 1)
					{
						System.out.println("INTEGER " + str.substring(beg, index + 1));
						index++;
						break;
					}
					
					next = str.charAt(index + 1);
					
					if(!Character.isDigit(next) && next != '.')
					{
						System.out.println("INTEGER " + str.substring(beg, index + 1));
						index++;
						curr = str.charAt(index);
						break;
					}
					
					else if(next == '.')
					{
						index++;
						curr = str.charAt(index);
						next = str.charAt(index + 1);
						while(index < str.length())
						{
							if(Character.isDigit(next))
							{
								index++;
								curr = str.charAt(index);
								if(index == str.length() - 1)
								{
									System.out.println("FLOAT " + str.substring(beg, index + 1));
									index++;
									break;
								}
								next = str.charAt(index + 1);
								if(!Character.isDigit(next) && next != '.')
								{
									System.out.println("FLOAT " + str.substring(beg, index + 1));
									index++;
									curr = str.charAt(index);
									break;
								}
							}
							
							else
							{
								System.out.println("Error at index " + (index));
								System.exit(0);
							}
						}
					}
				}//end if
				
				else if(next == '.')
				{
					index++;
					curr = str.charAt(index);
					next = str.charAt(index + 1);
					while(index < str.length())
					{
						if(Character.isDigit(next))
						{
							index++;
							curr = str.charAt(index);
							next = str.charAt(index + 1);
							if(!Character.isDigit(next) && next != '.')
							{
								System.out.println("FLOAT " + str.substring(beg, index + 1));
								index++;
								curr = str.charAt(index);
								break;
							}
						}
						
						else
						{
							System.out.println("Error at index " + (index + 1));
							System.exit(0);
						}
					}
				}
				
				else
				{
					if(curr >= '0' && curr <= '9')
						System.out.println("INTEGER " + curr);
					if(index == str.length() - 1)
						break;
					index++;
					curr = str.charAt(index);
					break;
				}
			}while(index < str.length());
		}//end if
	
	
	//if current character is a letter
	//////////////////////////////////
		else if(curr >= 'a' && curr <= 'z')
		{
			do
			{
				//read for more letters and digits
				if(Character.isLetter(next))
				{
					index++;
					if(index == str.length())
					{
						String sub = str.substring(beg, index);
						if(sub.matches("read") || sub.matches("write"))
							System.out.println("KEYWORD " + sub);
						else
							System.out.println("IDENTIFIER " + sub);
						break;
					}
					curr = str.charAt(index);
					if(index == str.length() - 1)
					{
						String sub = str.substring(beg, index + 1);
						if(sub.matches("read") || sub.matches("write"))
							System.out.println("KEYWORD " + sub);
						else
							System.out.println("IDENTIFIER " + sub);
						index++;
						break;
					}
					next = str.charAt(index + 1);
					if(Character.isDigit(next))
					{
						index++;
						curr = str.charAt(index);
						next = str.charAt(index + 1);
						if(next == '(' || next == ')' || next == '+' || next == '-' || next == '*' || next == '/' || next == ';' || next == '=' || next == ' ')
						{
							System.out.println("IDENTIFIER " + str.substring(beg, index + 1));
							index++;
							curr = str.charAt(index);
							break;
						}
						
						else if (Character.isLetter(next))
						{
							index++;
							curr = str.charAt(index);
							next = str.charAt(index + 1);
						}
						
						else
						{
							String sub = str.substring(beg, index + 1);
							if(sub.matches("read") || sub.matches("write"))
								System.out.println("KEYWORD " + sub);
							else
								System.out.println("IDENTIFIER " + sub);
							index++;
							System.out.println("Error at index " + (index));
							System.exit(0);
						}
					}
					else if(!Character.isDigit(next) && !Character.isLetter(next) && next != '.')
					{
						String sub = str.substring(beg, index + 1);
						if(sub.matches("read") || sub.matches("write"))
							System.out.println("KEYWORD " + sub);
						else
							System.out.println("IDENTIFIER " + sub);
						index++;
						curr = str.charAt(index);
						break;
					}
					else if(next == '.')
					{
						String sub = str.substring(beg, index + 1);
						if(sub.matches("read") || sub.matches("write"))
							System.out.println("KEYWORD " + sub);
						else
							System.out.println("IDENTIFIER " + sub);
						index++;
						System.out.println("Error at index " + (index));
						System.exit(0);
					}
				}
				
				else if(Character.isDigit(next))
				{
					index++;
					curr = str.charAt(index);
					next = str.charAt(index + 1);
					if(next == '(' || next == ')' || next == '+' || next == '-' || next == '*' || next == '/' || next == ';' || next == '=' || next == ' ')
					{
						System.out.println("IDENTIFIER " + str.substring(beg, index + 1));
						index++;
						curr = str.charAt(index);
						break;
					}
					
					else if (Character.isLetter(next))
					{
						index++;
						curr = str.charAt(index);
						next = str.charAt(index + 1);
					}
					
					else
					{
						String sub = str.substring(beg, index + 1);
						if(sub.matches("read") || sub.matches("write"))
							System.out.println("KEYWORD " + sub);
						else
							System.out.println("IDENTIFIER " + sub);
						index++;
						System.out.println("Error at index " + (index + 1));
						System.exit(0);
					}
				}//end if
				
				else if(!Character.isDigit(next) && !Character.isLetter(next) && next != '.')
				{
					System.out.println("IDENTIFIER " + str.substring(beg, index + 1));
					index++;
					curr = str.charAt(index);
					break;
				}
				
				else
				{
					System.out.println("Error at index " + (index));
					System.exit(0);
				}
			}while(index < str.length());
		}//end if
		
		
	//if the current character is invalid 
	/////////////////////////////////////
		else
		{
			System.out.println("Error at index " + (index));
			System.exit(0);
		}
			
	}//end print_next_token
	
	/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	||																						||
	||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

	public static void main(String[] args) 
	{
		String s = "x = 12.78 ; y = apple + 5 * orange;z=3*(4 * y)  ";
		//String s = "read write 34 +5.678 -789.001 goodread+-*  ";
		//String s = " int y = 7 ; double z = 78.01  ";
		//String s = " qwerty := 1234";
		//String s = " total is 23. dollars ";
		//String s = "x = art2.1b";
		//String s = "   ";
		System.out.printf("Input String: '%s'\n", s);
		LexAnalyzer lex = new LexAnalyzer(s.toLowerCase());
		System.out.println("\nToken List\n" + "----------\n");
		lex.printTokenList();
	}

}