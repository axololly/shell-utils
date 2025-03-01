# Clear the screen of anything beforehand
Invoke-Expression "cls"

# Create the output directories
Invoke-Expression "mkdir './bin/share' -Force | Out-Null"

Write-Output "Compiling standard version..."

# Compile a standard version of the executable.
# This will run fine on my machine.
Invoke-Expression "g++ -std=c++23 utils/copy/*.cpp -o bin/copy.exe"

# Alias the file.
Copy-Item -Path "bin/copy.exe" -Destination "bin/cp.exe"

# If the original source code couldn't compile, exit here.
if ($LASTEXITCODE != 0) {
    Break
}

Invoke-Expression "cls"

Write-Output "Compiling shareable version..."

# Compile a shareable, but heavier version, that packs the required
# DLLs with it. This circumvents the MinGW issue of missing DLLs.
Invoke-Expression "g++ -std=c++23 -static -static-libgcc -static-libstdc++ utils/copy/*.cpp -o bin/share/copy.exe"

# Alias the file.
Copy-Item -Path "bin/share/copy.exe" -Destination "bin/share/cp.exe"

Invoke-Expression "cls"

Write-Output "Compiled both versions!"