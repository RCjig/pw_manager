import sqlite3

con = sqlite3.connect('pw.db')
cur = con.cursor()

cur.execute("CREATE TABLE passwords (id INTEGER PRIMARY KEY AUTOINCREMENT, website TEXT, username/email TEXT, password INTEGER);")

con.commit()
con.close()
