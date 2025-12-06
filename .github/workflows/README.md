# GitHub Actions Workflows

## Trigger DocHub Update

This workflow automatically triggers the DocHub documentation site to update when changes are pushed to the `main` branch.

### Setup

1. **Create a GitHub Personal Access Token (PAT)**:
   - Go to GitHub Settings → Developer settings → Personal access tokens → Tokens (classic)
   - Generate a new token with `repo` scope
   - Copy the token

2. **Add the token as a secret in this repository**:
   - Go to this repository's Settings → Secrets and variables → Actions
   - Click "New repository secret"
   - Name: `DOCHUB_TRIGGER_TOKEN`
   - Value: Paste your PAT
   - Click "Add secret"

3. **Verify the dochub repository name**:
   - The workflow is configured to trigger `thisiskushal31/dochub`
   - If your dochub repository has a different name, update the `repository` field in `.github/workflows/trigger-dochub.yml`

### How it works

- When you push to the `main` branch, this workflow sends a `repository_dispatch` event to the dochub repository
- The dochub repository's `update-content.yaml` workflow listens for this event and automatically updates the documentation site
- The workflow can also be manually triggered from the Actions tab

