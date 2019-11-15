//PRABHJOT SINGH MATHARU
//0860228

public static void delete()
	{
		System.out.print("Enter the file name you want to delete: ");
		String filename = in.nextLine();

		String help = "Selected help\r\n" +
				"The user will be asked to enter a file name to be deleted.\r\n" +
				"If the file exists, it will be deleted.\r\n" +
				"Otherwise, an error message will appear.\r\n";
	//Java File delete() method can be used to delete files.
    // Java file delete method returns true if file gets deleted
    // and returns false if file doesn’t exist.

		while(filename.equals("/h"))
		{
			System.out.println(help);
			System.out.print("Enter the file name you want to delete: ");
			filename = in.nextLine();
		}


		if (new File(filename).delete() == false)
		{
			System.out.println("unable to delete the selected file becuz of some error.");
		}
		else
			System.out.println("The file has been deleted.");
	}




