import os

def replace_env(file_path, env_vars):
  """
  Replaces placeholders in a file with values from environment variables.
  """
  with open(file_path, 'r') as f_in, open(f_in.name + '.tmp', 'w') as f_out:
    for line in f_in:
      for key, value in env_vars.items():
        line = line.replace(f"%{key}%", value)
      f_out.write(line)
  os.rename(f_in.name + '.tmp', f_in.name)

# Get environment variables from the .env file
env_vars = dict(line.strip().split('=') for line in open('.env'))

# Replace placeholders in your code file (replace "main.cpp" with your actual file)
replace_env("src/main.cpp", env_vars)
