# GitHub Actions Workflows

## Trigger DocHub Update

This workflow automatically triggers the DocHub documentation site to update when changes are pushed to the `main` branch.

### Setup

1. **Create a GitHub Personal Access Token (PAT)**:

   **Option A: Classic Token (Recommended)**
   - Go to GitHub Settings → Developer settings → Personal access tokens → **Tokens (classic)**
   - Click "Generate new token (classic)"
   - Give it a descriptive name (e.g., "DocHub Trigger Token")
   - **IMPORTANT**: Select the `repo` scope (this gives full access to repositories)
   - Set expiration as needed
   - Click "Generate token"
   - **Copy the token immediately** (you won't be able to see it again)

   **Option B: Fine-grained Token**
   - Go to GitHub Settings → Developer settings → Personal access tokens → **Fine-grained tokens**
   - Click "Generate new token"
   - Give it a descriptive name (e.g., "DocHub Trigger Token")
   - Set expiration as needed
   - **Repository access**: Select "Only select repositories" and choose `thisiskushal31/dochub`
   - **Repository permissions**:
     - **Contents**: Read and write (REQUIRED for repository_dispatch)
     - **Actions**: Read and write (optional, but recommended)
   - Click "Generate token"
   - **Copy the token immediately** (you won't be able to see it again)

2. **Add the token as a secret in this repository**:
   - Go to this repository's Settings → Secrets and variables → Actions
   - Click "New repository secret"
   - Name: `DOCHUB_TRIGGER_TOKEN`
   - Value: Paste your PAT
   - Click "Add secret"

3. **Verify the dochub repository name**:
   - The workflow is configured to trigger `thisiskushal31/dochub`
   - If your dochub repository has a different name, update the repository name in `.github/workflows/trigger-dochub.yml`

### Troubleshooting

**Error: "Resource not accessible by personal access token"**

This usually means:
1. **For Classic Tokens**: The PAT doesn't have the `repo` scope - make sure you selected `repo` when creating the token
2. **For Fine-grained Tokens**: The PAT doesn't have "Contents" write permission - you need "Read and write" access to Contents for the `thisiskushal31/dochub` repository
3. The PAT doesn't have access to the target repository - ensure the token has access to `thisiskushal31/dochub`
4. The token might be expired - check the token expiration date in GitHub Settings

**To fix:**
- **If using Classic Token**: Create a new PAT with the `repo` scope
- **If using Fine-grained Token**: Edit your existing token and add "Contents" permission with "Read and write" access for `thisiskushal31/dochub`
- Make sure you're logged in as a user who has write access to the dochub repository
- Update the `DOCHUB_TRIGGER_TOKEN` secret with the new/updated token

### How it works

- When you push to the `main` branch, this workflow sends a `repository_dispatch` event to the dochub repository
- The dochub repository's `update-content.yaml` workflow listens for this event and automatically updates the documentation site
- The workflow can also be manually triggered from the Actions tab

