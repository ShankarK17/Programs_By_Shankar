final class Admin{ // this class (marked final) cannot be inherited 
	private String key;
}

class Moderator extends Admin{ // invalid as the Admin class Admin is set final
	int mod_id;
}



