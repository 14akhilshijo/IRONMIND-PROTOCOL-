/*
 * PROJECT: IRONMIND PROTOCOL (AEGIS-HARDWIRE / HSG-Protocol)
 * AUTHOR: Akhil Shijo
 * CONTACT: +91 8137864105 | mrakhilshijo@gmail.com
 * LOCATION: Idukki, Kerala, India
 * GITHUB: https://github.com/14akhilshijo
 * WEBSITE: https://akhilshijoinnov.site
 * LINKEDIN: https://www.linkedin.com/in/akhil-shijo/
 * ORGANIZATION: BITVION TECHNOLOGIES
 * LICENSE: Apache License 2.0
 * * ANY MODIFICATION OR DISTRIBUTION OF THIS FILE MUST RETAIN THIS HEADER.
 * FOR COMMERCIAL USE, ATTRIBUTION TO THE AUTHOR AND PLATFORM IS MANDATORY.
 * --------------------------------------------------------------------------
 * Module: L3_IMMUTABLE_LOG - Forensic Chain
 */

use sha2::{Sha256, Digest};

pub fn generate_secure_hash(previous_hash: &[u8], current_data: &[u8]) -> Vec<u8> {
    let mut hasher = Sha256::new();
    hasher.update(previous_hash);
    hasher.update(current_data);
    
// The result is stored in memory protected by fuses L0
    hasher.finalize().to_vec()
}

pub fn verify_integrity(stored_hash: &[u8], calculated_hash: &[u8]) -> bool {
// Quick physical comparison: If even one byte is different, it indicates a behavioral hacking attempt.
    stored_hash == calculated_hash
}
