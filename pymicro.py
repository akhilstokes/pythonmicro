import tkinter as tk
from tkinter import messagebox

def calculate_bmi(weight, height):
    return weight / (height ** 2)

def on_calculate_button_click():
    try:
        weight = float(weight_entry.get())
        height = float(height_entry.get())

        if weight <= 0 or height <= 0:
            raise ValueError("Both weight and height must be positive values.")

        bmi = calculate_bmi(weight, height)

        classification = ""
        color = ""
        tip = ""

        if bmi < 18.5:
            classification = "Underweight"
            color = "blue"
            tip = "You may need to gain weight in a healthy way."
        elif bmi < 24.9:
            classification = "Normal weight"
            color = "green"
            tip = "You’re in a healthy weight range!"
        elif bmi < 29.9:
            classification = "Overweight"
            color = "orange"
            tip = "Consider making small adjustments to your diet and increasing physical activity."
        else:
            classification = "Obesity"
            color = "red"
            tip = "It's recommended that you consult with a healthcare provider to develop a weight management plan."

        result_label.config(text=f"Your BMI is: {round(bmi, 2)}", fg=color)
        classification_label.config(text=f"Classification: {classification}", fg=color)
        tip_label.config(text=f"Tip: {tip}")

    except ValueError as e:
        messagebox.showerror("Input Error", f"Invalid input: {e}")

root = tk.Tk()
root.title("BMI Calculator")
root.configure(bg="black")

tk.Label(root, text="Enter your weight in kg:", font=("Arial", 12), bg="black", fg="white").pack(pady=10)
weight_entry = tk.Entry(root, font=("Arial", 12), bg="gray", fg="white", width=20)
weight_entry.pack(pady=5)

tk.Label(root, text="Enter your height in meters:", font=("Arial", 12), bg="black", fg="white").pack(pady=10)
height_entry = tk.Entry(root, font=("Arial", 12), bg="gray", fg="white", width=20)
height_entry.pack(pady=5)

calculate_button = tk.Button(root, text="Calculate BMI", font=("Arial", 12), bg="lightgray", fg="black", command=on_calculate_button_click)
calculate_button.pack(pady=20)

result_label = tk.Label(root, text="Your BMI is: ", font=("Arial", 14, "bold"), bg="black", fg="white")
result_label.pack(pady=5)

classification_label = tk.Label(root, text="Classification: ", font=("Arial", 14), bg="black", fg="white")
classification_label.pack(pady=5)

tip_label = tk.Label(root, text="Tip: ", font=("Arial", 12), bg="black", fg="white")
tip_label.pack(pady=10)

root.mainloop()