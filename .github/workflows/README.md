# GitHub Actions Workflows

## Trigger DocHub Update

This workflow automatically triggers the DocHub documentation site to update when changes are pushed to the `main` branch.

### Setup

1. **Create a GitHub Personal Access Token (PAT)**:
   - Go to GitHub Settings → Developer settings → Personal access tokens → Tokens (classic)
   - Click "Generate new token (classic)"
   - Give it a descriptive name (e.g., "DocHub Trigger Token")
   - **IMPORTANT**: Select the `repo` scope (this gives full access to repositories)
   - Set expiration as needed
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
1. The PAT doesn't have the `repo` scope - make sure you selected `repo` when creating the token
2. The PAT doesn't have access to the target repository - ensure the token was created by a user who has access to `thisiskushal31/dochub`
3. The token might be expired - check the token expiration date in GitHub Settings

**To fix:**
- Create a new PAT with the `repo` scope
- Make sure you're logged in as a user who has write access to the dochub repository
- Update the `DOCHUB_TRIGGER_TOKEN` secret with the new token

### How it works

- When you push to the `main` branch, this workflow sends a `repository_dispatch` event to the dochub repository
- The dochub repository's `update-content.yaml` workflow listens for this event and automatically updates the documentation site
- The workflow can also be manually triggered from the Actions tab

