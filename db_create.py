import sqlite3

con = sqlite3.connect('pw.db')
cur = con.cursor()

cur.execute("CREATE TABLE passwords (id INTEGER PRIMARY KEY AUTOINCREMENT, website TEXT, user TEXT, password TEXT);")

con.commit()
con.close()
