def continuous_mean_calculation():
    old_average = 0.0  # Initial average
    count = 0          # Number of values entered
    
    print("Enter floating-point numbers (or 'x' to end program):")
    
    while True:
        user_input = input("-> ")
        
        # Check for exit condition
        if user_input.lower() == "x":
            print("End of Program.")
            break
        
        # Validate and process input
        try:
            new_value = float(user_input)
            count += 1
            # Update running average
            new_average = old_average + (new_value - old_average) / count
            old_average = new_average
            print(f"Current average after {count} numbers: {new_average:.2f}")
        
        except ValueError:
            print("Invalid input. Please enter a number or 'x' to quit.")

if __name__ == "__main__":
    continuous_mean_calculation()