# Generate bin file for efuse block3
#
# python .\gen_bin.py
# espefuse -p COM5 burn_block_data --offset 0 BLOCK3 efuse_block3.bin
# 
# espefuse -p COM5 summary
#

data = "pl_52gjw_0003|1.6"
encoded = data.encode("utf-8")

# Ensure that the encoded data doesn't exceed 32 bytes
if len(encoded) > 32:
    raise ValueError("Encoded data exceeds 32 bytes")

# Calculate the number of padding bytes needed
padding_length = 32 - len(encoded)

# Create padded data by appending null bytes
padded_data = encoded + b'\x00' * padding_length

# Write the padded data to a binary file
with open("efuse_block3.bin", "wb") as bin_file:
    bin_file.write(padded_data)
