import os

def zero_pad_filenames(directory):
    # List all files in the directory
    files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]
    
    for file in files:
        # Split the number and the rest of the filename
        if '.' in file:
            parts = file.split('.', 1)
            if parts[0].isdigit():  # Ensure the first part is a number
                num = int(parts[0])  # Convert to integer to handle numbers correctly
                new_name = f"{num:04}.{parts[1]}"  # Zero-pad the number
                old_path = os.path.join(directory, file)
                new_path = os.path.join(directory, new_name)
                os.rename(old_path, new_path)
                print(f"Renamed: {file} -> {new_name}")

# Run the function in the current directory
zero_pad_filenames(".")
