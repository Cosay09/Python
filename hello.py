import tkinter as tk

root = tk.Tk()
root.title("Hello World App")
root.geometry("300x200")
root.configure(bg='lightblue')
root.resizable(False, False)

label = tk.Label(root, text="Hello, World!", font=("Arial", 24), bg='lightblue')
label.pack(expand=True)

root.mainloop()