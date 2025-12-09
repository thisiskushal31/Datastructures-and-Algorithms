### Hashing

Hashing is the process of transforming any given key or a string of characters into another value. This is usually represented by a shorter, fixed-length value or key that represents and makes it easier to find or employ the original string.   

The most popular use for hashing is the implementation of hash tables. A hash table stores key and value pairs in a list that is accessible through its index. Because key and value pairs are unlimited, the hash function will map the keys to the table size. A hash value then becomes the index for a specific element.    

**Hash Function:** A function that converts a given big phone number to a small practical integer value. The mapped integer value is used as an index in hash table. In simple terms, a hash function maps a big number or string to a small integer that can be used as index in hash table. 
A good hash function should have following properties   

> 1) Efficiently computable.    
> 2) Should uniformly distribute the keys (Each table position equally likely for each key)    

*For example for phone numbers a bad hash function is to take first three digits. A better function is consider last three digits. Please note that this may not be the best hash function. There may be better ways.*    

**Hash Table:** An array that stores pointers to records corresponding to a given phone number. An entry in hash table is NIL if no existing phone number has hash function value equal to the index for the entry.  

#### Collision Handling

Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision and must be handled using some collision handling technique. Following are the ways to handle collisions: 

> Chaining: The idea is to make each cell of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.
    
> Open Addressing: In open addressing, all elements are stored in the hash table itself. Each table entry contains either a record or NIL. When searching for an element, we examine the table slots one by one until the desired element is found or it is clear that the element is not in the table.

   
A hash function generates new values according to a mathematical hashing algorithm, known as a hash value or simply a hash. To prevent the conversion of hash back into the original key, a good hash always uses a one-way hashing algorithm.    

Hashing is relevant to -- but not limited to -- data indexing and retrieval, digital signatures, cybersecurity and cryptography.     

#### Hashing Reallife Use Cases

##### Data retrieval

Hashing uses functions or algorithms to map object data to a representative integer value. A hash can then be used to narrow down searches when locating these items on that object data map.

For example, in hash tables, developers store data -- perhaps a customer record -- in the form of key and value pairs. The key helps identify the data and operates as an input to the hashing function, while the hash code or the integer is then mapped to a fixed size.

Hash tables support functions that include the following:

    insert (key, value)
    get (key)
    delete (key)

![DataRetrieval](./assets/Hashing_Data_Retrieval.png)  

##### Digital signatures

In addition to enabling rapid data retrieval, hashing helps encrypt and decrypt digital signatures used to authenticate message senders and receivers. In this scenario, a hash function transforms the digital signature before both the hashed value (known as a message digest) and the signature are sent in separate transmissions to the receiver.   

Upon receipt, the same hash function derives the message digest from the signature, which is then compared with the transmitted message digest to ensure both are the same. In a one-way hashing operation, the hash function indexes the original value or key and enables access to data associated with a specific value or key that is retrieved.   

![DigitalSignatures](./assets/Hashing_Digital_Signature_Process.png)

    When someone creates and encrypts a digital signature with a private 
    key, hash data is also created and encrypted. The signer's public key 
    then enables the recipient to decrypt the signature

#### Credits

> [Hashing by TechTarget](https://www.techtarget.com/searchdatamanagement/definition/hashing)   
> [Hashing by GeekforGeeks](https://www.geeksforgeeks.org/hashing-set-1-introduction)      


#### Link for more information:

 [Hashing By Geeks for Geeks](https://www.geeksforgeeks.org/hashing-set-1-introduction) follow along with the blogs given in table of contents on the GFG Website. 
